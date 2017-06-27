/**

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

#include <stdio.h>
#include <vector>

class Solution {
public:
    const std::vector<int> prime_factor = {2, 3, 5};
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num > 1){
            bool flag = false; 
            for (int i = 0; i < prime_factor.size(); i++){
                if (num % prime_factor[i] == 0){
                    num /= prime_factor[i];
                    flag = true;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution soluton;
    if (soluton.isUgly(14))
        printf("is ugly number\n");
    else
        printf("is not ugly number\n");
    return 0;
}