/**
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/

#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
        }
        return n * (n + 1) / 2 - sum;
    }
};

int main()
{
    return 0;
}