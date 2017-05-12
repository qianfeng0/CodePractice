/**
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include <stdio.h>
#include <math.h>
class Solution {
public:
    int mySqrt(int x) {
        double ans = x;
        double delta = 0.0001;
        while(fabs(ans * ans - x) > delta){
            ans = (ans + x / ans)/2;
        }
        return ans;
    }
};

int main(){
    Solution solution;
    int a = 4;
    printf("%d\n", solution.mySqrt(a));
    return 0;
}