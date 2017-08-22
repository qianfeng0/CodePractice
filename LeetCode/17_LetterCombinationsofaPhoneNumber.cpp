/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<string> digitToLetter = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    vector<string> result;

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return result;

        string letters;
        dfs(digits, 0, letters);
        return result;
    }

    void dfs(string &digits, int cur_digit, string& letters){
        if (cur_digit >= digits.length()){
            result.push_back(letters);
            return;
        }

        int num = digits[cur_digit] - '0';
        for (char c : digitToLetter[num]){
            letters.push_back(c);
            dfs(digits, cur_digit + 1, letters);
            letters.pop_back();
        }
    }
};

int main()
{
    string str = "23";
    Solution solution;
    vector<string> res = solution.letterCombinations(str);

    for(string s : res){
        cout << s << endl;
    }

    return 0;
}