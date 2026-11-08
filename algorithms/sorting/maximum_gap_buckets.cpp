#include<iostream>
#include<vector>
#include <climits>

using namespace std;

struct bucket {
	int min;
	int max;
	bucket() :min(INT_MAX), max(INT_MIN) {}
};

int seed;
int rand()
{
	return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}
int rand32() {
	return ((rand() << 16) + (rand() << 1) + rand() % 2);
}

int main() {
	long long int n;
	cin >> n >> seed;

	vector<bucket>buckets(n - 1);

	vector<int>nums;
	int maxValue = INT_MIN;
	int minValue = INT_MAX;


	for (long long i = 0; i < n; ++i) {
		nums.push_back(rand32());
	}

	for (auto x : nums) {
		if (x >= maxValue) {
			maxValue = x;
		}
		if (x <= minValue) {
			minValue = x;
		}
	}
	long long dif = 1LL * maxValue - minValue;
	
	if (maxValue == minValue) {
		cout << 0 << '\n';
		return 0;
	}

	for (auto x : nums) {
		long long index =
			(1LL * x - minValue) * (n - 1) / dif;
		if (index >= n - 1) {
			index = n - 2;
		}
		if (buckets[index].max <= x) {
			buckets[index].max = x;
		}
		if (buckets[index].min >= x) {
			buckets[index].min = x;
		}
	}

	long long maxGap = 0;
	long long lastRight = minValue;

	for (const auto& b : buckets) {
		if (b.min > b.max) {
			continue;
		}

		long long gap = 1LL * b.min - lastRight;

		if (gap > maxGap) {
			maxGap = gap;
		}

		lastRight = b.max;
	}

	cout << maxGap << '\n';

	return 0;
}