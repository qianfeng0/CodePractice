/**
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        vec.assign(rowIndex + 1, 0);
        vec[0] = 1;
        for (int i = 0; i <= rowIndex; i++){
            for (int j = i; j > 0; j--){
                vec[j] = vec[j] + vec[j - 1];
            }
        }
        return vec;
    }
};

int main()
{
    Solution solution;
    vector<int> pr = solution.getRow(4);
    for (int i = 0; i < pr.size(); i++)
        printf("%d ", pr[i]);
    printf("\n");
    return 0;
}

