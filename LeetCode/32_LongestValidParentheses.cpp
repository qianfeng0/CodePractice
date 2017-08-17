/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <string>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
DP思路：
 ()(()())
002002048
*/

class Solution {
public:
    int longestValidParentheses(string s) {

        s = ')' + s;
        vector<int> dp(s.size(), 0);
        int dp_size = s.size();

        int res_max = 0;
        for (int i = 1; i < dp_size; i++){
            if (s[i] == ')'){
                if (s[i - dp[i-1] - 1] == '(')
                    dp[i] = dp[i-1] + 2;
                dp[i] += dp[i - dp[i]];
            }
            res_max = std::max(dp[i], res_max);
        }
        return res_max;
    }
};

int main()
{
    return 0;
}