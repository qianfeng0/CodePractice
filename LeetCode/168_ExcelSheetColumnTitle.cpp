/**
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0){
            n--;
            res.insert(res.begin(), 'A' + n % 26);
            n /= 26;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    printf("%s\n", solution.convertToTitle(27).data());
    return 0;
}