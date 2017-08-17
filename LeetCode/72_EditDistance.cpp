/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
DP思路
    #   a   b   c
#   0   1   1   2   
b   1   1   1   2
i   2   2   2   3   
c   3   3   3   2

[i][j]不相同，可以传递dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1
[i][j]相同，可传dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        int rows = dp.size();
        int cols = dp[0].size();

        for (int i = 1; i < rows; i++){
            dp[i][0] = dp[i-1][0] + 1;
        }
        for (int j = 1; j < cols; j++){
            dp[0][j] = dp[0][j-1] + 1;
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1]) + 1);
                }
                else{
                    dp[i][j] = 1 + std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[rows-1][cols-1];
    }
};

int main()
{
    return 0;
}