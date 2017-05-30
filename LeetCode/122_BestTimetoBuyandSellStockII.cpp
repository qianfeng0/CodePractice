/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <stdio.h>
#include <vector>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int buy = INT32_MAX;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < buy)
                buy = prices[i];
            else{
                 sum += prices[i] - buy;
                 buy = prices[i];
            }
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    printf("max:%d\n", solution.maxProfit(prices));
    return 0;
}