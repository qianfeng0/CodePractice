/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        if (0 == n)
            return res;

        addParenthesis(res, "", n, n);

        return res;
    }

    void addParenthesis(vector<string> &res, string cur, int left, int right){
        if (0 == left && 0 == right){
            res.push_back(cur);
            return;
        }

        if (left != 0){
            addParenthesis(res, cur+"(", left - 1, right);
        }
        if (right != 0 && left < right){
            addParenthesis(res, cur+")", left, right - 1);
        }
    }
};

int main()
{
    return 0;
}