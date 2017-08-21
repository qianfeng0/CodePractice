/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; 
        int j = height.size() - 1;
        int res = 0;
        //int res = std::min(height[i], height[j])
        int temp = 0;
        while(i < j){
            temp = std::min(height[i], height[j]) * (j - i);
            if (temp > res){
                res = temp;
            }

            if (height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return res;
    }
};

int main()
{
    vector<int> height = {1, 1};
    Solution solution;
    printf("%d\n", solution.maxArea(height));
    return 0;
}