/**
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stdio.h>
#include <vector>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class bst{
public:
    static void insert(TreeNode* &root, TreeNode* newNode)
    {
        if(root == NULL)
            root = newNode;
        else if(newNode->val < root->val)
            insert(root->left, newNode);
        else
            insert(root->right, newNode);
    }

    static void preorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }

    static void del(TreeNode* &root)
    {
        if(root == NULL)
            return;
        del(root->left);
        del(root->right);
        delete root;
        root = NULL;
    }
};

using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* bst = NULL;
        generateBST(bst, nums, 0, nums.size() - 1);
        return bst;
    }

    void generateBST(TreeNode* &root, vector<int>& nums, int left, int right)
    {
        if(left > right)
            return;
        else if(left == right)
            root = new TreeNode(nums[left]);
        else{
            int mid = (left + right) / 2;
            root = new TreeNode(nums[mid]);
            generateBST(root->left, nums, left, mid - 1);
            generateBST(root->right, nums, mid + 1, right);
        }
    }
};


int main()
{
    std::vector<int> nums = {1,5,14,20,55,102,412,522,854};
    Solution solution;
    TreeNode* bstree =  solution.sortedArrayToBST(nums);
    bst::preorder(bstree);
    printf("\n");
    bst::del(bstree);
    return 0;
}