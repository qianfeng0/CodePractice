/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
dp
dp[i][j] -> 字串i~j是否回文
dp[i][j] = dp[i+1][j-1] && (s[i] == s[j])
           j-i <= 2 && (s[i] == s[j])
*/
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome_dp(string s) {
        if (s.length() <= 1)
            return s;
        string res = s.substr(0, 1);

        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        for (int i = 0; i < len; i++){
            dp[i][i] = true;
        }

        for (int j = 1; j < len; j++){
            for (int i = 0; i < j; i++){
                dp[i][j] = (s[i] == s[j]) && (j -i <= 2 || dp[i+1][j-1]);
                if (dp[i][j]){
                    if (j-i+1 > res.length()){
                        res = s.substr(i, j-i+1);
                    }
                }
            }
        }

        return res;
    }

    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        int len = s.length();
        string res = s.substr(0, 1);

        for (int i = 0; i < len; i++){
            int L = i, R = i;
            string temp;
            temp = getPalindrome(s, L, R);
            if (temp.length() > res.length()){
                res = temp;
            }

            if (R+1 < len){
                temp = getPalindrome(s, L, R+1);
                if (temp.length() > res.length()){
                    res = temp;
                }
            }
        }
        return res;
    }

    string getPalindrome(string s, int L, int R){
        int len = s.length();

        while(L>= 0 && R < len && s[L] == s[R]){
            L--;
            R++;
        }

        return s.substr(L + 1, R - (L + 1));
    }
};

int main()
{
    return 0;
}