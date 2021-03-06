/**
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0};
        int m2[256] = {0};
        int len = s.size();
        for (int i = 0; i < len; i++){
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "egg";
    string t = "add";

    if (solution.isIsomorphic(s, t))
        printf("is isomorphic\n");
    else
        printf("is not isomorphic\n");
    return 0;
}