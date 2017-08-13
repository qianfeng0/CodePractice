/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
/*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        set<int> s;

        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            s.insert(nums1[i]);
        }

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            set<int>::iterator ite;
            ite = s.find(nums2[i]);
            if ( ite != s.end() )
            {
                out.push_back(nums2[i]);
                s.erase(ite);
            }
        }
        return out;
    }
*/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        set<int> s(nums1.begin(), nums1.end());

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            set<int>::iterator ite;
            ite = s.find(nums2[i]);
            if ( ite != s.end() )
            {
                out.push_back(nums2[i]);
                s.erase(ite);
            }
        }
        return out;
    }   
};

int main()
{
    return 0;
}