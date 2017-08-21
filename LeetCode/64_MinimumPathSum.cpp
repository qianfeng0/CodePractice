/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        int rows = dp.size();
        int cols = dp[0].size();

        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < cols; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[rows-1][cols-1];
    }
};

int main()
{
    return 0;
}