/**
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <vector>
#include <stdio.h>

using namespace std;
#if (0)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        *(result.end() - 1) += 1;
        int a = 0;
        for(int i = result.size() - 1; i >= 0; i--){
            result[i] += a;
            a = 0;
            if(result[i] > 9){
                a = 1;
                result[i] -= 10;
            }
        }
        if(a == 1)
            result.insert(result.begin(), 1);
        return result;
    }
};
#endif

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main(){
    
    Solution solution;
    vector<int> nums = {9,9,9};
    vector<int> plus1 = solution.plusOne(nums);
    for(int i = 0; i < plus1.size(); i++)
        printf("%d ", plus1[i]);
    printf("\n");
    return 0;
}