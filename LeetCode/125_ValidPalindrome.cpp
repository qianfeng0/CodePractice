/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            while (isalnum(s[i]) == false && i < j)
                i++;
            while (isalnum(s[j]) == false && i < j)
                j--;
            if (toupper(s[i]) != toupper(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string str = "A man, a plan, a canal: Panama";
    if(solution.isPalindrome(str))
        printf("is palindrome\n");
    else
        printf("is not palindrome\n");
    return 0;
}