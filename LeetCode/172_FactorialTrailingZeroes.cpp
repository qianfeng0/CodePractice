/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

#include <stdio.h>

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n){
            n /= 5;
            res += n;
        }
        /*
        for (int i = 1; i <= n; i++){
            int temp = i;
            while(temp != 0){
                if (temp % 5 == 0)
                    res++;
                else
                    break;
                temp /= 5;
            }
        }
        */
        return res;
    }
};

int main()
{
    Solution solution;
    printf("%d\n", solution.trailingZeroes(1808548329));
    return 0;
}