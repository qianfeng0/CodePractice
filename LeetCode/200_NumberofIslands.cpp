/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        mRows = grid.size();
        if (!mRows)
            return 0;
        mCols = grid[0].size();
        if (!mCols)
            return 0;
        mMatrix = grid;

        int res = 0;
        for (int i = 0; i < mRows; i++){
            for (int j = 0; j < mCols; j++){
                if (mMatrix[i][j] == '1'){
                    res++;
                    dfs(i,j);
                }
            }
        }
        return res;
    }

    void dfs(int x, int y){
        if (mMatrix[x][y] == '0')
            return;
        
        mMatrix[x][y] = '0';
        if (x > 0)
            dfs(x - 1, y);
        if (x < mRows - 1)
            dfs(x + 1, y);
        if (y > 0)
            dfs(x, y - 1);
        if (y < mCols - 1)
            dfs(x, y + 1);
    }

    int mRows;
    int mCols;
    vector<vector<char>> mMatrix;
};

int main()
{
    //vector<vector<char>> grid = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
    vector<vector<char>> grid = {{'1','1','1','1','0'}, 
                                 {'1','1','0','1','0'}, 
                                 {'1','1','0','0','0'}, 
                                 {'0','0','0','0','0'}};
    Solution solution;

    int res = solution.numIslands(grid);

    printf("%d\n", res);
    return 0;
}