#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool canMake24(vector<double>nums) {
	if (nums.size() == 1) {
		return abs(nums[0] - 24.0) < 1e-6;
	}
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			vector<double>nextnum(0);
			double a = nums[i];
			double b = nums[j];
			nextnum.push_back(a + b);
			nextnum.push_back(a - b);
			nextnum.push_back(b - a);
			nextnum.push_back(a * b);
			nextnum.push_back(a / b);
			nextnum.push_back(b / a);

			for (auto x : nextnum) {
				vector<double> nextNums = nums;
				nextNums.erase(nextNums.begin() + j);
				nextNums.erase(nextNums.begin() + i);
				nextNums.push_back(x);
				if (canMake24(nextNums)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	vector<double >nums(4);
	for (int i = 0; i < 4; i++) {
		cin >> nums[i];
	}
	if (canMake24(nums))cout << "Yes";
	else cout << "No";
	return 0;
}