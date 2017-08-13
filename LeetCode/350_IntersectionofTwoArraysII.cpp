/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
#if (0)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> res;
        int size1 = nums1.size();
        int size2 = nums2.size();

        int i = 0, j = 0;
        while (i < size1 && j < size2){
            if (nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
#endif

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        std::map<int, int> m;

        for (int i = nums1.size() - 1; i >= 0; i--){
            m[nums1[i]]++;
        }

        for (int i = nums2.size() - 1; i >= 0; i--){
            if (m[nums2[i]]-- > 0){
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};

int main()
{
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2};

    Solution solution;
    std::vector<int> res = solution.intersect(nums1, nums2);

    for (int i : res)
        printf("%d ", i);
    printf("\n");
    return 0;
}