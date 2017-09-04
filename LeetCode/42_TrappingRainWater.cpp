/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        
        int left = 0, right = height.size() - 1;

        while(left < right){
            int minh = min(height[left], height[right]);

            if (minh == height[left]){
                while(++left < right && height[left] < minh)
                    res += minh - height[left];
            }
            else{
                while( left < --right && height[right] < minh)
                    res += minh - height[right];
            }
        }

        return res;
    }
};

int main()
{
    vector<int> h = {4, 2, 3};
    Solution solution;

    int res = solution.trap(h);

    return 0;
}