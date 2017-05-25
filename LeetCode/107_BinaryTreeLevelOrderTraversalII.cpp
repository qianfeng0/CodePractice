/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class bst
{
  public:
    static void insert(TreeNode* &root, TreeNode* newNode)
    {
        if (root == NULL)
            root = newNode;
        else if(newNode->val < root->val)
            insert(root->left, newNode);
        else
            insert(root->right, newNode);
    }

    static void preorder(TreeNode* root)
    {
        if (root == NULL)
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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> levelOrder;
        addLevel(levelOrder, 0, root);
        return levelOrder;
    }

    void addLevel(vector<vector<int>> &levelOrder, int level, TreeNode* root)
    {
        if(root == NULL)
            return;
        if(levelOrder.size() < level + 1)
            levelOrder.insert(levelOrder.begin(), vector<int>());
        addLevel(levelOrder, level + 1, root->left);
        addLevel(levelOrder, level + 1, root->right);
        levelOrder[levelOrder.size() - 1 - level].push_back(root->val);
    }
};

void printLevelOrder(vector<vector<int>> &levelOrder)
{
    for (int i = 0; i < levelOrder.size(); i++){
        for(int j = 0; j < levelOrder[i].size(); j++){
            printf("%d ", levelOrder[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    TreeNode* bstree = NULL;
    bst::insert(bstree, new TreeNode(60));
    bst::insert(bstree, new TreeNode(20));
    bst::insert(bstree, new TreeNode(81));
    bst::insert(bstree, new TreeNode(25));
    bst::insert(bstree, new TreeNode(2));
    bst::insert(bstree, new TreeNode(10));
    bst::insert(bstree, new TreeNode(55));
    bst::insert(bstree, new TreeNode(71));

    bst::preorder(bstree);
    printf("\n");

    Solution solution;
    vector<vector<int>> levelOrder = solution.levelOrderBottom(bstree);
    printLevelOrder(levelOrder);
    bst::del(bstree);
    return 0;
}