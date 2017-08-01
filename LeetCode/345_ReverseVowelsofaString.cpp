/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

#include <string>
#include <iostream>

using namespace std;

const string vowels = "aeiou";

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        bool iVowel = false, jVowel = false;
        char temp;
        while(i < j){
            if (iVowel && jVowel){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
                iVowel = false;
                jVowel = false;
            }

            if (!iVowel){
                if (vowels.find(tolower(s[i])) != string::npos){
                    iVowel = true;
                }
                else{
                    i++;
                }
            }

            if (!jVowel){
                if (vowels.find(tolower(s[j])) != string::npos){
                    jVowel = true;
                }
                else{
                    j--;
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string str = "leetcode";

    cout << solution.reverseVowels(str) << endl;
    return 0;
}