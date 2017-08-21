/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int temp = 0;
        for (int i = 0; i < size - 2; i++){
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int l = i + 1, r = size - 1;
            while (l < r){
                temp = nums[i] + nums[l] + nums[r];
                if (temp == 0){
                    res.push_back(vector<int>({nums[i], nums[l], nums[r]}));
                    while(++l < r && nums[l] == nums[l-1]);
                    while(l < --r && nums[r] == nums[r + 1]);
                }
                else if (temp > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}

