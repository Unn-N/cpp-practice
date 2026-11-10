#include<iostream>
#include<vector>

using namespace std;
// [约定] 堆用 1 下标：a[1..n]，孩子 2i/2i+1，父亲 i/2，非叶结点 i <= n/2

bool isMaxHeap(const vector<int>& nums, int n) {
	for (int i = 1; i <= n / 2; i++) {
		if (nums[i] < nums[2 * i] || (((2 * i + 1) <= n) && (nums[i] < nums[2 * i + 1]))) {
			return false;
		}
	}

	return true;
}

bool isMinHeap(const vector<int>& nums, int n) {
	for (int i = 1; i <= n / 2; i++) {
		if (nums[i] > nums[2 * i] || (((2 * i + 1) <= n) && (nums[i] > nums[2 * i + 1]))) {
			return false;
		}
	}

	return true;
}

void siftDownMax(vector<int>& nums, int n, int i) {
	while (2 * i <= n) {
		int l = 2 * i;
		int r = 2 * i + 1;
		int child = l;
		if (r <= n) {
			if (nums[r] >= nums[l])
				child = r;
			else
				child = l;
		}

		if (nums[i] >= nums[child])
			break;

		else {
			swap(nums[i], nums[child]);
			i = child;
		}
	}
}
void siftDownMin(vector<int>& nums, int n, int i) {
	while (2 * i <= n) {
		int l = 2 * i;
		int r = 2 * i + 1;
		int child = l;
		if (r <= n) {
			if (nums[r] <= nums[l])
				child = r;
			else
				child = l;
		}

		if (nums[i] <= nums[child])
			break;

		else {
			swap(nums[i], nums[child]);
			i = child;
		}
	}
}

void buildMaxHeap(vector<int>& nums, int n) {
	for (int i = n / 2; i >= 1; i--) {
		siftDownMax(nums, n, i);
	}
}
void buildMinHeap(vector<int>& nums, int n) {
	for (int i = n / 2; i >= 1; i--) {
		siftDownMin(nums, n, i);
	}
}

void print(const vector<int>& nums) {
	for (int i = 1; i < (int)nums.size()-1; i++) {
		cout << nums[i] << " ";
	}
	cout << nums.back();
}

int main() {
	int n;
	cin >> n;
	vector<int>nums(n + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> nums[i];
	}

	bool isMax = isMaxHeap(nums, n);
	bool isMin = isMinHeap(nums, n);

	if (isMax && !isMin) {
		cout << "max ";
		buildMinHeap(nums, n);
		print(nums);
		return 0;
	}
	if (isMin && !isMax) {
		cout << "min ";
		buildMaxHeap(nums, n);
		print(nums);

		return 0;
	}
	if (isMin && isMax) {
		cout << "max min ";

		return 0;
	}
	if (!isMin && !isMax) {
		buildMaxHeap(nums, n);
		print(nums);
		return 0;
	}
}