/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size() - 1;
        while(last >= 0){
            if( (s[last] >= 'a' && s[last] <= 'z') || (s[last] >= 'A' && s[last] <= 'Z') )
                break;
            last--;
        }
        int i = last;
        for(i; i >= 0; i--){
            if(s[i] == ' ')
                break;
        }
        return last - i;
    }
};

int main(){
    Solution solution;
    string str = "Today is a nice day";
    printf("%d\n", solution.lengthOfLastWord(str));
    return 0;
}