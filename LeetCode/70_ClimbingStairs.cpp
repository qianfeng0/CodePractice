/**
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/
#include <assert.h>
#include <stdio.h>

#if (0)
class Solution {
public:
    int cmn(int m, int n){
        assert(m >= n);
        int ans = 1;
        for(int i = m; i > m - n; i--){
            ans *= i;
        }
        for(int i = n; i > 0; i--){
            ans /= i;
        }
        return ans;
    }
    int climbStairs(int n) {
        int count = 0;
        int s1,s2;
        s2 = n / 2;
        s1 = n % 2;

        while(s2 >= 0){
            int m = s2 + s1;
            int n = s2 < s1 ? s2 : s1;
            count += cmn(m,n);
            s2--;
            s1 += 2;
        }
        return count;
    }
};
#endif

class Solution {
public:
    int climbStairs(int n) {
        int cur = 1, next = 1;
        while(n--){
            next = cur + next;
            cur = next - cur;
        }
        return cur;
    }
};

int main(){
    Solution solution;
    printf("%d\n", solution.climbStairs(35));
    return 0;
}