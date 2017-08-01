/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        char temp;
        for (; i < j; i++, j--)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};

int main()
{
    Solution solution;

    string str = "hello";
    cout << solution.reverseString(str) << endl;
    return 0;
}