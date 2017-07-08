/**
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/
#include <algorithm>

class Solution {
public:
#if (0)
    bool isPowerOfThree(int n) {
        return std::fmod(std::log10(n) / std::log10(3), 1) == 0;
    }
#else
    //3^19 = 1162261467, int max
    bool isPowerOfThree(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }
#endif
};


int main()
{
    return 0;
}