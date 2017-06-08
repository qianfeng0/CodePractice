/**
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
/*
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 0; i < n; i++){
            if (isPrimes(i))
                res++;
        }
        return res;
    }

    bool isPrimes(int n)
    {
        if (n == 0 || n == 1)
            return false;
        else if (n == 2)
            return true;
        
        for (int i = 2; i < n; i++){
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
*/
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 0; i < sqrt(n); i++){
            if(prime[i]){
                for (int j = i*i; j < n; j += i)
                    prime[j] = false;
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};

int main()
{
    Solution solution;
    printf("%d\n", solution.countPrimes(4));
    return 0;
}