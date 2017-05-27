/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

#include <stdio.h>
#include <algorithm>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Bst{
public:
    static void insert(TreeNode* &root, TreeNode* newNode)
    {
        if (root == NULL)
            root = newNode;
        else if (newNode->val < root->val)
            insert(root->left, newNode);
        else
            insert(root->right, newNode);
    }

    static void preorder(TreeNode* root)
    {
        if(root ==NULL)
            return;
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }

    static void del(TreeNode* &root)
    {
        if (root == NULL)
            return;
        del(root->left);
        del(root->right);
        delete root;
        root = NULL;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        //int l = btDepth(root->left);
        //int r = btDepth(root->right);
        //return (std::abs(l-r) <= 1) && (l != -1) && (r != -1);
        return (btDepth(root) != -1);
    }

    int btDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int l = btDepth(root->left);
        int r = btDepth(root->right);

        if(l == -1 || r == -1 || std::abs(l-r) > 1)
            return -1;
        else
            return std::max(l,r) + 1; 
    }
};

int main()
{
    TreeNode* bstree = NULL;
    /*
    Bst::insert(bstree, new TreeNode(50));
    Bst::insert(bstree, new TreeNode(10));
    Bst::insert(bstree, new TreeNode(80));
    Bst::insert(bstree, new TreeNode(5));
    Bst::insert(bstree, new TreeNode(1));
    */
    Bst::insert(bstree, new TreeNode(1));
    Bst::insert(bstree, new TreeNode(2));
    Bst::insert(bstree, new TreeNode(3));
    Bst::preorder(bstree);
    printf("\n");

    Solution solution;
    if (solution.isBalanced(bstree))
        printf("is balanced\n");
    else
        printf("is not balanced\n");
    Bst::del(bstree);
    return 0;
}