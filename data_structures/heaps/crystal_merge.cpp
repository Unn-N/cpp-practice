#include<iostream>
#include<vector>

using namespace std;

void push(vector<long long>& nums, long long x) {
	nums.push_back(x);
	int i = static_cast<int>(nums.size()) - 1;

	while (i > 0 && nums[i] < nums[(i - 1) / 2]) {
		swap(nums[i], nums[(i - 1) / 2]);
		// [踩坑] 曾写成 i = i - 1 / 2；除法先算，整数 1 / 2 为 0，导致 i 不变。
		// 交换后要跟随新插入的数移动到父节点，继续检查上浮。
		i = (i - 1) / 2;
	}
}

long long pop(vector<long long>& nums) {
	long long min = nums[0];
	swap(nums[0], nums[nums.size() - 1]);
	nums.pop_back();

	int i = 0;
	int n = static_cast<int>(nums.size());

	while (2 * i + 1 < n) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int child = l;
		if (r < n) {
			if (nums[r] <= nums[l])
				child = r;
		}
		if (nums[i] >= nums[child]) {
			swap(nums[i], nums[child]);
			i = child;
		}
		// [踩坑] 最初遗漏了这个退出分支：不需要交换时 i 不变，会陷入死循环。
		else
			break;
	}
	return min;
}

int main() {
	int n;
	cin >> n;
	vector<long long>nums;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		push(nums, num);
	}
	// [踩坑] 曾在合并结束后用 nums[0] 作为答案，那只是最终水晶的数值。
	// 总消耗需要从 0 开始逐轮累加；只有一块水晶时不合并，答案为 0。
	long long sum = 0;
	while (nums.size() > 1) {
		long long a = pop(nums);
		long long b = pop(nums);

		long long c = a + b;

		sum += c;
		push(nums, c);
	}

	cout << sum;
	return 0;
}