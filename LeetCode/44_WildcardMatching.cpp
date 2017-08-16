/**
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


/*
完全匹配
1.if (p[j] == s[i] || p[j] == '?')
    dp[i][j] = dp[i][j]
符号*
2.if (p[j] == '*')
    dp[i][j] = dp[i][j-1] ||    in this case, * counts as empty
                dp[i-1][j]      in this case, * counts as one or multiple
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int rows = s.size() + 1;
        int cols = p.size() + 1;

        vector<vector<bool>> dp(rows, vector<bool>(cols, false));
        
        dp[0][0] = true;

        for (int i = 1; i < rows; i++){
            dp[i][0] = false;
        }

        for (int j = 1; j < cols; j++){
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (p[j-1] == s[i-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[rows-1][cols-1];
    }
};

int main()
{
    string s = "aa";
    string p = "aa";

    Solution solution;
    if (solution.isMatch(s,p))
        printf("true\n");
    else
        printf("false\n");
}