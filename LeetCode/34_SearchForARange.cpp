/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right){
            int mid = (left + right) / 2;

            if (nums[mid] == target){
                left = right = mid;

                while (left > 0 && nums[left-1] == target){
                    left--;
                }

                while (right < nums.size() - 1 && nums[right + 1] == target){
                    right++;
                }

                return vector<int>{left, right};
            }

            if (target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return vector<int>(2,-1);
    }
};

int main()
{
    return 0;
}