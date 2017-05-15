/**
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <vector>
#include <stdio.h>
#include <stdint.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int index = m + n - 1;
        while(index1 >= 0 && index2 >= 0){
            nums1[index--] = nums1[index1] > nums2[index2] ? nums1[index1--] : nums2[index2--];
        }
        while(index2 >= 0){
            nums1[index--] = nums2[index2--];
        }
        return;
    }
};

void printVector(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return;
}
int main(){
    Solution solution;

    vector<int> num1 = {1,2,8,14,20};
    vector<int> num2 = {3,5,8,10,11};
    int m = num1.size();
    int n = num2.size();
    num1.resize(m + n);
    printVector(num1);
    printVector(num2);
    solution.merge(num1, m, num2, n);
    printVector(num1);
    return 0;
}
