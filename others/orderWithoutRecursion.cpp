#include <stdio.h>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class bst
{
public:
    static void insert(TreeNode* &root, TreeNode* newTreeNode){
        if (root == NULL)
            root = newTreeNode;
        else if (newTreeNode->val < root->val)
            insert(root->left, newTreeNode);
        else
            insert(root->right, newTreeNode);
    }

    static void delTree(TreeNode* &root){
        if (root == NULL)
            return;
        delTree(root->left);
        delTree(root->right);
        delete root;
        root = NULL;
    }

    static void preOrder(TreeNode* root)
    {
        if (root == NULL)
            return;
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }

    static void inOrder(TreeNode* root)
    {
        if (NULL == root)
            return;
        inOrder(root->left);
        printf("%d ", root->val);
        inOrder(root->right);
    }

    static void postOrder(TreeNode* root)
    {
        if (NULL == root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->val);
    }

    static void inOrderWithoutRecursion(TreeNode* root)
    {
        TreeNode* curNode = root;
        std::stack<TreeNode*> s;

        while(!s.empty() || curNode){
            if (curNode){
                s.push(curNode);
                curNode = curNode->left;
            }
            else{
                curNode = s.top();
                printf("%d ", curNode->val);
                s.pop();
                curNode = curNode->right;
            }
        }
    }

    static void preOrderWithoutRecursion(TreeNode* root)
    {
        TreeNode* curNode = root;
        std::stack<TreeNode*> s;

        while(!s.empty() || curNode)
        {
            if (curNode){
                printf("%d ", curNode->val);
                s.push(curNode);
                curNode = curNode->left;
            }
            else{
                curNode = s.top();
                s.pop();
                curNode = curNode->right;
            }
        }
    }

    static void postOrderWithoutRecursion(TreeNode* root)
    {
        TreeNode* curNode = root;
        TreeNode* preVisit = NULL;
        std::stack<TreeNode*> s;

        while(curNode)
        {
            s.push(curNode);
            curNode = curNode->left;
        }

        while(!s.empty())
        {
            curNode = s.top();
            if (curNode->right == NULL || curNode->right == preVisit){
                printf("%d ", curNode->val);
                s.pop();
                preVisit = curNode;
            }
            else{
                curNode = curNode->right;
                while(curNode){
                    s.push(curNode);
                    curNode = curNode->left;
                }
            }
        }
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

    printf("preorder:\n");
    bst::preOrder(tree);
    printf("\n");

    printf("preOrderWithoutRecursion:\n");
    bst::preOrderWithoutRecursion(tree);
    printf("\n");

    printf("inorder:\n");
    bst::inOrder(tree);
    printf("\n");

    printf("inOrderWithoutRecursion:\n");
    bst::inOrderWithoutRecursion(tree);
    printf("\n");

    printf("postorder:\n");
    bst::postOrder(tree);
    printf("\n");

    printf("postOrderWithoutRecursion:\n");
    bst::postOrderWithoutRecursion(tree);
    printf("\n");

    bst::delTree(tree);
    return 0;
}