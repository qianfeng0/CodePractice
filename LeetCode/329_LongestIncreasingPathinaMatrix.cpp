/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        mRows = matrix.size();
        if (mRows == 0)
            return 0;
        
        mCols = matrix[0].size();
        if (mCols == 0)
            return 0;

        mMatrix = matrix;

        mPathLen.resize(mRows);
        for (int i = 0; i < mRows; i++)
            mPathLen[i].assign(mCols, 0);
        
        int res = 0;
        for (int i = 0; i < mRows; i++){
            for (int j = 0; j < mCols; j++){
                res = max(res, dfs(i, j));
            }
        }


        return res;
    }

private:
    int dfs(int x, int y)
    {
        if (mPathLen[x][y] != 0)
            return mPathLen[x][y];

        int left = 0, right = 0, up = 0, down = 0;
        if (y > 0 && mMatrix[x][y - 1] > mMatrix[x][y])
            left = dfs(x, y - 1);
        if (y < (mCols - 1) && mMatrix[x][y + 1] > mMatrix[x][y])
            right = dfs(x, y + 1);
        if (x > 0 && mMatrix[x-1][y] > mMatrix[x][y])
            up = dfs(x-1, y);
        if (x < (mRows - 1) && mMatrix[x+1][y] > mMatrix[x][y])
            down = dfs(x+1, y);
        
        mPathLen[x][y] = 1 + std::max(std::max(left, right), std::max(up, down));
        return mPathLen[x][y];
    }

    vector<vector<int>> mMatrix;
    vector<vector<int>> mPathLen;
    int mRows;
    int mCols;
};

int main()
{
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};

    Solution solution;
    int res = solution.longestIncreasingPath(matrix);
    printf("%d\n", res);
    return 0;
}