/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        
        dfs(nums, res, cur, visited);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur, vector<bool> &visited){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        int size = nums.size();
        for (int i = 0; i < size; i++){
            if (visited[i])
                continue;
            
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, res, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }

};

int main()
{
    return 0;
}