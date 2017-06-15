/**
Given an integer, write a function to determine if it is a power of two.
*/
#include <stdio.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else if (n == 1)
            return true;
        else{
            while (n > 1){
                if (n % 2 != 0)
                    return false;
                n /= 2;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    if (solution.isPowerOfTwo(6))
        printf("is power of two\n");
    else
        printf("is not power of two\n");
    return 0;
}