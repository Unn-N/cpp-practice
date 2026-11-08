#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

// 运算符优先级
int level(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	if (op == '*' || op == '/') {
		return 2;
	}
	return -1;
}

// 执行符号栈栈顶的一次运算
bool calculate(vector<double>& nums, vector<char>& ops) {
	if (nums.size() < 2 || ops.empty()) {
		return false;
	}

	double right = nums.back();
	nums.pop_back();

	double left = nums.back();
	nums.pop_back();

	char op = ops.back();
	ops.pop_back();

	double res;

	if (op == '+') {
		res = left + right;
	}
	else if (op == '-') {
		res = left - right;
	}
	else if (op == '*') {
		res = left * right;
	}
	else if (op == '/') {
		if (abs(right) < 1e-12) {
			return false;
		}
		res = left / right;
	}
	else {
		return false;
	}

	nums.push_back(res);
	return true;
}

// 检查表达式是否合法、数字是否匹配，并计算结果
bool scanAndCalculate(
	const string& str,
	const vector<int>& expected,
	double& result
) {
	vector<double> nums;
	vector<char> ops;

	// used[x] 表示表达式中使用了多少次数字 x
	vector<int> used(14, 0);

	// true：期待数字或左括号
	// false：期待运算符或右括号
	bool expectNum = true;

	for (int i = 0; i < str.size();) {
		// ① 读取数字
		if (isdigit(str[i])) {
			// 当前位置不允许出现数字
			if (!expectNum) {
				return false;
			}

			// 操作数只能是 1~13，因此不允许以 0 开头
			if (str[i] == '0') {
				return false;
			}

			int num = 0;

			while (i < str.size() && isdigit(str[i])) {
				num = num * 10 + (str[i] - '0');

				// 立即限制大小，也避免超长数字造成 int 溢出
				if (num > 13) {
					return false;
				}

				i++;
			}

			used[num]++;

			// 数字使用次数超过给定数量
			if (used[num] > expected[num]) {
				return false;
			}

			nums.push_back(num);
			expectNum = false;
		}

		// ② 左括号
		else if (str[i] == '(') {
			if (!expectNum) {
				return false;
			}

			ops.push_back('(');
			i++;

			// 左括号后面仍然期待数字或左括号
		}

		// ③ 右括号
		else if (str[i] == ')') {
			// 例如 ()、(3+) 都不合法
			if (expectNum) {
				return false;
			}

			// 计算当前括号内尚未完成的运算
			while (!ops.empty() && ops.back() != '(') {
				if (!calculate(nums, ops)) {
					return false;
				}
			}

			// 没有找到与之匹配的左括号
			if (ops.empty()) {
				return false;
			}

			ops.pop_back();  // 弹出 '('
			i++;

			expectNum = false;
		}

		// ④ 普通运算符
		else if (level(str[i]) != -1) {
			// 例如 *3、4**3 都不合法
			if (expectNum) {
				return false;
			}

			char op = str[i];

			// 优先完成已经可以确定运算顺序的部分
			while (!ops.empty()
				&& ops.back() != '('
				&& level(ops.back()) >= level(op)) {
				if (!calculate(nums, ops)) {
					return false;
				}
			}

			ops.push_back(op);
			i++;

			expectNum = true;
		}

		// ⑤ 非法字符
		else {
			return false;
		}
	}

	// 表达式不能以运算符结尾，也不能是空表达式
	if (expectNum) {
		return false;
	}

	// 扫描结束，完成剩余运算
	while (!ops.empty()) {
		// 剩余左括号说明括号不匹配
		if (ops.back() == '(') {
			return false;
		}

		if (!calculate(nums, ops)) {
			return false;
		}
	}

	// 最终必须恰好剩下一个计算结果
	if (nums.size() != 1) {
		return false;
	}

	// 四个数字必须全部使用，且次数一致
	if (used != expected) {
		return false;
	}

	result = nums.back();
	return true;
}

int main() {
	vector<int> expected(14, 0);

	// 读取给定的四个数字
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		expected[x]++;
	}

	int m;
	cin >> m;

	int answer = 0;

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		double result;

		if (scanAndCalculate(str, expected, result)
			&& abs(result - 24.0) < 1e-6) {
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}