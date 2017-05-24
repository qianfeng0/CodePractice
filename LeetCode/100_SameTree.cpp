/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


class bst
{
public:
    static void insert(TreeNode* &root, TreeNode* newNode){
        if (root == NULL)
            root = newNode;
        else if (newNode->val < root->val)
            insert(root->left, newNode);
        else
            insert(root->right, newNode);
    }

    static void travel(TreeNode* root){
        if(root == NULL)
            return;
        printf("%d ", root->val);
        travel(root->left);
        travel(root->right);
    }

    static void delTree(TreeNode* &root){
        if(root == NULL)
            return;
        delTree(root->left);
        delTree(root->right);
        delete root;
        root = NULL;
    }
};

int main()
{
    TreeNode* tree = NULL;
    bst::insert(tree,new TreeNode(50));
    bst::insert(tree,new TreeNode(5));
    bst::insert(tree,new TreeNode(8));
    bst::insert(tree,new TreeNode(60));
    bst::insert(tree,new TreeNode(58));
    bst::insert(tree,new TreeNode(30));
    bst::travel(tree);
    printf("\n");
    
    TreeNode* tree2 = NULL;
    bst::insert(tree2,new TreeNode(50));
    bst::insert(tree2,new TreeNode(5));
    bst::insert(tree2,new TreeNode(8));
    bst::insert(tree2,new TreeNode(20));
    bst::insert(tree2,new TreeNode(58));
    bst::insert(tree2,new TreeNode(30));
    bst::travel(tree2);
    printf("\n");

    Solution solution;
    if(solution.isSameTree(tree, tree2))
        printf("same\n");
    else
        printf("not same\n");

    bst::delTree(tree);
    return 0;
}
