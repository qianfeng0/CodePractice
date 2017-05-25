/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <stdio.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};

class bst
{
public:
    static void insert(TreeNode* &root, TreeNode* newNode){
        if(root == NULL)
            root = newNode;
        else if(newNode->val < root->val)
            insert(root->left, newNode);
        else
            insert(root->right, newNode);
    }

    static void preorder(TreeNode* root){
        if(root == NULL)
            return;
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }

    static void del(TreeNode* &root){
        if(root == NULL)
            return;
        del(root->left);
        del(root->right);
        delete root;
        root = NULL;
    }
};

int main()
{
    TreeNode* bstree = NULL;
    bst::insert(bstree, new TreeNode(60));
    bst::insert(bstree, new TreeNode(100));
    bst::insert(bstree, new TreeNode(1));
    bst::insert(bstree, new TreeNode(25));
    bst::insert(bstree, new TreeNode(50));

    bst::preorder(bstree);
    printf("\n");

    Solution solution;
    printf("max depth = %d\n", solution.maxDepth(bstree));
    bst::del(bstree);
}