/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r){
            int sum = numbers[l] + numbers[r];
            if (sum == target){
                vector<int> res = {l+1,r+1};
                return res;
            }
            else if (sum > target){
                r--;
            }
            else{
                l++;
            }
        }
        return vector<int>();
    }
};


int main()
{
    return 0;
}