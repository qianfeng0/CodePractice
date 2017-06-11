/**
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0)
            return false;
        set<int> s;
        for (int i = 0; i < nums.size(); i++){
            if (i > k)
                s.erase(nums[i - k - 1]);
            if (!s.insert(nums[i]).second)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,2,1};
    if (solution.containsNearbyDuplicate(nums, 1))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}