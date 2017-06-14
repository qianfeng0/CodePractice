/**
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        int count[256] = {0};
        for (int i = 0; i < s.size(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for (int i = 0; i < 256; i++){
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    if (solution.isAnagram(s, t))
        printf("is anagram\n");
    else
        printf("is not anagram\n");
    return 0;
}