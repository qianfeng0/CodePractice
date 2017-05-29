/**
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalT(numRows);
        for (int i = 0; i < numRows; i++){
            pascalT[i].resize(i+1);
            pascalT[i][0] = pascalT[i][i]= 1;
            for(int j = 1; j < i; j++)
                pascalT[i][j] = pascalT[i - 1][j - 1] + pascalT[i - 1][j];
        }       
        return pascalT; 
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> pas = solution.generate(5);
    for (int i = 0; i < pas.size(); i++){
        for (int j = 0; j < pas[i].size(); j++){
            printf("%d ", pas[i][j]);
        }
        printf("\n");
    }
    return 0;
}