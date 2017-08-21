/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        if (!rows)
            return 0;
        int cols = obstacleGrid[0].size();
        if (!cols)
            return 0;

        vector<vector<int>> map(rows, vector<int>(cols, 0));

        if (obstacleGrid[0][0] == 0)
            map[0][0] = 1;

        for (int i = 1; i < rows; i++){
            if (obstacleGrid[i][0] == 1)
                continue;
            map[i][0] = map[i-1][0];
        }

        for (int j = 1; j < cols; j++){
            if (obstacleGrid[0][j] == 1)
                continue;
            map[0][j] = map[0][j-1];
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (obstacleGrid[i][j] == 1)
                    continue;
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[rows-1][cols-1];
    }
};

int main()
{
    return 0;
}