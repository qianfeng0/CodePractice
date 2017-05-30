/**
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>
#include <vector>

using namespace std;

// a^a = 0;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++)
            a ^= nums[i];
        return a;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0,0,4,5,5};
    printf("%d\n", solution.singleNumber(nums));
    return 0;
}