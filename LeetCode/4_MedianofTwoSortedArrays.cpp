/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/*
分析：找两个已排序数组的中位数，其实就是将两个有序数组有序合并后找第K小的数。
而找第K小的数，可以将K平分到两个数组中，
然后利用一个重要的结论：如果A[k/2-1]<B[k/2-1]，那么A[0]~A[k/2-1]一定在第k小的数的序列当中，可以用反证法证明。
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if ((total & 0x1) == 1){
            return findKth(nums1, nums2, total / 2 + 1);
        }
        else{
            vector<int> n1;
            vector<int> n2;
            double sum = 0;

            n1 = nums1;
            n2 = nums2;
            sum += findKth(n1, n2, total / 2);

            n1 = nums1;
            n2 = nums2;
            sum += findKth(n1, n2, total / 2 + 1);
            return sum / 2;
        }
    }

    double findKth(vector<int>& nums1, vector<int>& nums2, int k){
        if (nums1.size() > nums2.size()){
            return findKth(nums2, nums1, k);
        }

        if (nums1.size() == 0){
            return nums2[k-1];
        }

        if (k == 1){
            return std::min(nums1[0], nums2[0]);
        }

        int p1 = std::min(k/2, (int)nums1.size());
        int p2 = k - p1;    //共取k个数
        
        if (nums1[p1-1] < nums2[p2-1]){
            nums1.erase(nums1.begin(), nums1.begin() + p1);
            return findKth(nums1, nums2, k - p1);
        }
        else if (nums1[p1-1] > nums2[p2-1]){
            nums2.erase(nums2.begin(), nums2.begin() + p2);
            return findKth(nums1, nums2, k - p2);
        }
        else {
            return nums1[p1-1];
        }
    }
};

int main()
{
    vector<int> n1 = {1, 2};
    vector<int> n2 = {3, 4};

    Solution solution;
    cout << solution.findMedianSortedArrays(n1, n2) << endl;
    return 0;
}