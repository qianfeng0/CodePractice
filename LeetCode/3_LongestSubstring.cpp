/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;

        int subLength = 1;
        int pos = 0;
        int strLength = s.size();
        for(int i = 0; i < strLength; i++){
            int foundIndex = s.find(s[i], pos);
            if(foundIndex < i){
                pos = foundIndex + 1;
            }

            if(i - pos + 1 > subLength){
                subLength = i - pos + 1;
            }
        }
        return subLength;
    }
};

int main(){

    char chars[100];
    while(scanf("%s", chars)){
        if(chars[0] == '\0')
            break;
        string str(chars);

        Solution solution;
        printf("%d\n", solution.lengthOfLongestSubstring(str));
    }
    return 0;
}