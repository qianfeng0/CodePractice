/**
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

#include <stdio.h>
#include <stdint.h>



class Solution {
public:
    int reverse(int x) {
        long result = 0;

        while(x != 0){
            result = result * 10 + x % 10;
            x /= 10;
        }
        if( result < INT32_MIN || result > INT32_MAX)
            return 0;
        else
            return result;
    }
};

int main(){
    Solution solution;
    int input = 0;
    while(scanf("%d", &input)){
        printf("%d\n", solution.reverse(input));
    }

    return 0;
}