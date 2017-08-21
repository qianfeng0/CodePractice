/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/


#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/*
DP思路
dp[i][j]代表s[0-i]与p[0-j]是否匹配

情况：
完全匹配
1.if (p[j] == s[i] || p[j] == '.')
    dp[i][j] = dp[i-1][j-1]

*
2.if (p[j] == '*')
    if (p[j-1] != s[i]) -> dp[i][j] = dp[i][j-2]
    if (p[j-1] == s[i] || p[j-1] == '.') -> dp[i][j] = dp[i-1][j] ||    in this case, a* counts as multiple a 
                                                        dp[i][j-1] ||   in this case, a* counts as single a
                                                        dp[i][j-2]      in this case, a* counts as empty

http://www.jianshu.com/p/c09c4a3fc14a
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0)
            return s.size() == 0;

        if (p.size() == 1 || p[1] != '*'){
            if (!s.empty() && (p[0] == s[0] || p[0] == '.')){
                return isMatch(s.substr(1), p.substr(1));
            }
            else{
                return false;
            }
        }
        //x*
        else{
            if(isMatch(s, p.substr(2))){
                return true;
            }
            else if (!s.empty() && (p[0] == s[0] || p[0] == '.')){
                return isMatch(s.substr(1), p);
            }
            else{
                return false;
            }
        }
    }

    bool isMatch_dp(string s, string p) {

        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        int rows = dp.size();
        int cols = dp[0].size();

        //空串为true
        dp[0][0] = true;

        //初始化第0列， p为空串
        for (int i = 1; i < rows; i++){
            dp[i][0] = false;
        }

        //初始化第0行， s为空串, 只有x*能匹配空串，如果有*,值与p[0][j-2]相同
        for (int j = 1; j < cols; j++){
            if (p[j-1] == '*' && j > 1){
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                //字符匹配，传递[i-1][j-1]值
                if (p[j-1] == s[i-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*'){
                    if (p[j-2] == s[i-1] || p[j-2] == '.'){
                        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};

int main()
{
    string s = "aa";
    string p = ".*";

    Solution solution;
    if (solution.isMatch_dp(s,p))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}