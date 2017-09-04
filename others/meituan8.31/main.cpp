
/*
序列中任意个连续的元素组成的子序列称为该序列的子串。
现在给你一个序列P和一个整数K，询问元素和是K的倍数的子串的最大长度。
比如序列【1,2,3,4,5】，给定的整数K为 5，其中满足条件的子串为{5}、{2,3}、{1,2,3,4}、{1,2,3,4,5}，
那么答案就为 5，因为最长的子串为{1,2,3,4,5}；如果满足条件的子串不存在，就输出 0。

Input Sample 1
5
1 2 3 4 5
5
Input Sample 2
6
3 1 2 7 7 7
4
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int k;
	
	cin >> n;
	vector<int> nums(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	cin >> k;

	//处理
	vector<int> numsSum(nums.size() + 1, 0);
	for (int i = 0; i < n; i++) {
		numsSum[i + 1] = numsSum[i] + nums[i];
	}

	int res = 0;
	int size = numsSum.size();

	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j >= (i + 1); j--) {
			if (j - i < res) {
				break;
			}
			if ((numsSum[j] - numsSum[i]) % k == 0) {
				res = max(res, j - i);
				break;
			}
		}
	}

	cout << res << endl;
	return 0;
}

#if (0)
int main()
{
	int n;
	int k;
	vector<int> nums;

	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

	cin >> k;

	//处理
	vector<int> numsSum(nums.size() + 1, 0);
	for (int i = 0; i < n; i++) {
		numsSum[i + 1] = numsSum[i] + nums[i];
	}

	int res = 0;
	int size = numsSum.size();

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((numsSum[j] - numsSum[i]) % k == 0) {
				res = max(res, j - i);
			}
		}
	}

	cout << res << endl;
	return 0;
}
#endif