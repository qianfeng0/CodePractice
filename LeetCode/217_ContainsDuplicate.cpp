/**
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

*/

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set_nums;
        pair<set<int>::iterator, bool> part_nums;
        for (int i = 0; i < nums.size(); i++){
            part_nums = set_nums.insert(nums[i]);
            if (part_nums.second == false)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0,1,2,1,5,6,7};
    if (solution.containsDuplicate(nums))
        printf("contain duplicate\n");
    else
        printf("is not contain duplicate\n");
    return 0;
}