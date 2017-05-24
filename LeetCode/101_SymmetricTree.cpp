/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include <assert.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else
            return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};

class cbtree{
public:
    static TreeNode* creatFromArray(std::vector<int> &array){
        if(array.size() == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(array[0]);
        std::queue<TreeNode*> q;
        q.push(root);
        for(int i = 1; i < array.size(); i++){
            TreeNode* temp = q.front();
            if(temp->left == NULL){
                temp->left = new TreeNode(array[i]);
                q.push(temp->left);
            }
            else{ 
                assert(temp->right == NULL);
                temp->right = new TreeNode(array[i]);
                q.push(temp->right);
                q.pop();
            }
        }
        return root;
    }

    static void preOrder(TreeNode* root){
        if(root == NULL)
            return;
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
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
int main(){
    std::vector<int> array = {1,2,2,3,4,4,3};
    TreeNode* cbt = cbtree::creatFromArray(array);
    cbtree::preOrder(cbt);
    printf("\n");
    Solution solution;
    if(solution.isSymmetric(cbt))
        printf("Symmetric\n");
    else
        printf("not Symmetric\n");
    cbtree::del(cbt);
    return 0;
}