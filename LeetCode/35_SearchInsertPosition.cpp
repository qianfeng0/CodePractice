/**
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution{
  public:
    int searchInsert(vector<int> &nums, int target){
        int i = 0;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] >= target)
                break;
        }
        return i;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6, 10};
    printf("%d\n", solution.searchInsert(nums, 7));
}