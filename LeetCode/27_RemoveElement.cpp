/**
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[length++] = nums[i];
            }
        }
        return length;
    }
};

int main(){
    Solution solution;
    vector<int> vec = {3,2,2,3,4};

    int length = solution.removeElement(vec, 3);
    printf("%d\n", length);
    for (int i = 0; i < length; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
    return 0;
}