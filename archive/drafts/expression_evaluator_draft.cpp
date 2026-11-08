#include<iostream>
#include<vector>

using namespace std;

int level(char op) {
	if (op == '+' || op == '-')return 1;
	if (op == '*' || op == '/')return 2;
	return -1;
}

bool calculate(vector<double>& nums, vector<char>& ops) {
	if (nums.size() < 2 || ops.empty())return false;

	double a = nums[nums.size() - 2];
	double b = nums[nums.size() - 1];
	char op = ops[ops.size() - 1];
	double res;
	nums.pop_back();
	nums.pop_back();
	ops.pop_back();

	if (op == '+') {
		res = a + b;
	}
	if (op == '-') {
		res = a - b;
	}
	if (op == '*') {
		res = a * b;
	}
	if (op == '/') {
		if (abs(b) < 1e-6) {
			return false;
		}
		res = a / b;
	}
	nums.push_back(res);
	return true;
}

bool scanAndCalculate(const string& str, double& result) {
	int num = 0;
	vector<double>nums;
	vector<char>ops;

	bool expectNum = true;

	for (int i = 0; i < str.size();) {
		if (isdigit(str[i])) {
			int num = 0;
			while (i < str.size() && isdigit(str[i])) {
				num = num * 10 + (str[i] - '0');
				i++;
			}
			nums.push_back(num);
		}
		else if (str[i] == '(') {
			ops.push_back('(');
			i++;
		}
		else if (str[i] == ')') {
			while (!ops.empty() && ops.back() != '(') {
				if (!calculate(nums, ops)) {
					return false;
				}
			}
			ops.pop_back();
			i++;
		}
		else {
			char op = str[i];

			while (!ops.empty()
				&& ops.back() != '('
				&& level(ops.back()) >= level(op)) {
				if (!calculate(nums, ops)) {
					return false;
				}
			}

			ops.push_back(op);
			i++;

		}
	}
}

int main() {
	vector<int>nums(4);
	for (int i = 0; i < 4; i++) {
		cin >> nums[i];
	}
}