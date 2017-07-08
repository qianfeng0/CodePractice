/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        //int sum = 0;
        sumArray.push_back(0);
        for (int i = 0; i < nums.size(); i++){
        //for (auto i : nums){
            sumArray.push_back(sumArray.back() + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sumArray[j+1] - sumArray[i];
    }
    
private:
    vector<int> sumArray;
};

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(2,5) << endl;
}