/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void dfs(vector<int>& candidates, vector<vector<int>> &res, vector<int> &cur, int target)
    {
        if (target == 0){
            res.push_back(cur);
            return;
        }

        for (int candidate : candidates){
            if (cur.empty() || *(cur.end() - 1) <= candidate){
                if (target - candidate >= 0){
                    cur.push_back(candidate);
                    dfs(candidates, res, cur, target - candidate);
                    cur.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(candidates, res, cur, target);
        
        return res;
    }
};

int main()
{
    return 0;
}