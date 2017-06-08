/**
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        return max(dfs(nums, 0), dfs(nums, 1));
    }

    int dfs(vector<int>& nums, int index)
    {
        if (index >= nums.size())
            return 0;
        return max(dfs(nums, index + 2), dfs(nums, index + 3)) + nums[index];
    }
};
*/

//DP solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int notrob = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int currob = notrob + nums[i];
            notrob = max(rob, notrob);
            rob = currob;
        }
        return max(rob, notrob);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,5,2,4,0,3,9,7,4};
    printf("%d\n", solution.rob(nums));
    return 0;
}