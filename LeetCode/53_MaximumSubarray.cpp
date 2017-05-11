/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
#include <vector>
#include <stdio.h>
#include <stdint.h>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum > max)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", solution.maxSubArray(nums));
    return 0;
}