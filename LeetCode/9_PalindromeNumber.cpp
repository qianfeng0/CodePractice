/**
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <stdio.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0))
            return false;

        long reverse = 0;
        while(x > reverse){
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (reverse == x || reverse / 10 == x);
    }
};

int main(){
    Solution solution;

    int input = 0;
    while(scanf("%d", &input)){
        if(solution.isPalindrome(input))
            printf("is palindrome\n");
        else
            printf("is not palidrome\n");
    }
}