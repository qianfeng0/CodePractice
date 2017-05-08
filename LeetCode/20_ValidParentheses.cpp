/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(':
                    paren.push(s[i]);
                    break;
                case '[':
                    paren.push(s[i]);
                    break;
                case '{': 
                    paren.push(s[i]);
                    break;
                case ')':
                    if(paren.empty() || paren.top() != '(')
                        return false;
                    else
                        paren.pop();
                    break;
                case ']':
                    if(paren.empty() || paren.top() != '[')
                        return false;
                    else
                        paren.pop();
                    break;
                case '}':
                    if(paren.empty() || paren.top() != '{')
                        return false;
                    else
                        paren.pop();
                    break;
            }
        }
        return paren.empty();
    }
};

int main(){
    Solution solution;
    string str = "54(f)fr";
    if(solution.isValid(str))
        cout << "is valid" << endl;
    else
        cout << "is not valid" << endl;
    return 0;
}