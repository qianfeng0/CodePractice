/**
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res_str;
        if (root == NULL)
            return res_str;
        
        dfs(root, to_string(root->val), res_str);
        return res_str;
    }

    void dfs (TreeNode* root, string str, vector<string> &res_str)
    {
        if (!root->left && !root->right){
            res_str.push_back(str);
            return;
        }
        if (root->left)
            dfs(root->left, str + "->" + to_string(root->left->val), res_str);
        if (root->right)
            dfs(root->right, str + "->" + to_string(root->right->val), res_str);
    }
};

int main()
{
    return 0;
}