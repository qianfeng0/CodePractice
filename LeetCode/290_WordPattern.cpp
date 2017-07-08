/**
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> s2i;
        stringstream ss(str);
        string word;
        int i = 0;
        for (i = 0; ss >> word; i++){
            if ( i == pattern.size() || p2i[pattern[i]] != s2i[word])
                return false;
            p2i[pattern[i]] = s2i[word] = i + 1;
        }
        return i == pattern.size();
    }
};

int main()
{
    Solution solution;
    string pattern = "abba";
    string str = "dog cat cat dog";
    if (solution.wordPattern(pattern, str))
        printf("is word pattern\n");
    else
        printf("is not word pattern\n");
    return 0;
}