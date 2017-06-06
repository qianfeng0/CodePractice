/**
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/


#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reversal(nums, 0, nums.size() - k - 1);
        reversal(nums, nums.size() - k, nums.size() - 1);
        reversal(nums, 0, nums.size() - 1);
    }

    void reversal(vector<int> &nums, int start, int end)
    {
        int temp;
        for (;start < end; start++, end--){
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> vec = {1,2,3,4,5,6,7};
    solution.rotate(vec, 3);
    for (int i = 0; i < vec.size(); i++)
        printf("%d ", vec[i]);
    printf("\n");
    return 0;
}