#include <stack>
#include "stdio.h"

    //       10
    //       /\
    //    7     12
    //   /\      /\
    // 0   9       100

struct BTreeNode {
    int value;
    BTreeNode *left;
    BTreeNode *right;
    BTreeNode(int v):value(v), left(nullptr), right(nullptr){};
};

class BinaryTree
{
public:
    BinaryTree(/* args */);
    ~BinaryTree();

    bool addNode_loop(int v);
    void release_loop();

    void preOrder_recursion(BTreeNode *tree);
    void inOrder_recursion(BTreeNode *tree);
    void postOrder_recursion(BTreeNode *tree);

    void preOrder_loop(BTreeNode *tree);
    void inOrder_loop(BTreeNode *tree);
    void postOrder_loop(BTreeNode *tree);

    void release_recursion(BTreeNode* &tree);
public:
    BTreeNode *mpTree;
    /* data */
};

BinaryTree::BinaryTree(/* args */)
{
    mpTree = nullptr;
}

BinaryTree::~BinaryTree()
{

}

bool BinaryTree::addNode_loop(int v)
{
    BTreeNode *node = new BTreeNode(v);

    if (mpTree == nullptr) {
        mpTree = node;
        return true;
    }

    BTreeNode *cur_node = mpTree;
    BTreeNode *pre_node;
    while (cur_node != nullptr)
    {
        pre_node = cur_node;
        if (node->value < cur_node->value) {
            cur_node = cur_node->left;
        } else {
            cur_node = cur_node->right;
        }
    }

    if (node->value < pre_node->value) {
        pre_node->left = node;
    }else {
        pre_node->right = node;
    }

    return true;
}

void BinaryTree::release_loop()
{
    // std::stack<BTreeNode*> treeStack;
    // BTreeNode *cur_node = mpTree;
    // while (cur_node || !treeStack.empty())
    // {
    //     if (cur_node) {
    //         treeStack.push(cur_node);
    //         cur_node = cur_node->left;
    //     } else {
    //         cur_node = treeStack.top();
    //         treeStack.pop();
    //         if (cur_node == nullptr) {

    //         } else {
    //             //right
    //             treeStack.push(cur_node);
    //             treeStack.push(nullptr);
    //         }
    //     }

    // }
    
}

void BinaryTree::preOrder_loop(BTreeNode *tree)
{
    if (tree == nullptr)
        return;
    
    std::stack<BTreeNode*> treestack;
    BTreeNode *cur_node = tree;
    while(cur_node || !treestack.empty()) {
        if (cur_node) {
            printf("preOrder_loop, %d\n", cur_node->value);     //当前节点访问完
            treestack.push(cur_node->right);                    //右节点入栈
            cur_node = cur_node->left;                          //往左走到底
        } else {
            cur_node = treestack.top();                         //弹右节点
            treestack.pop();
        }
    }
}

void BinaryTree::inOrder_loop(BTreeNode *tree)
{
    if (tree == nullptr)
        return;
    
    std::stack<BTreeNode*> treestack;
    BTreeNode *cur_node = tree;
    while (cur_node || !treestack.empty())
    {
        if (cur_node) {
            treestack.push(cur_node);   //入栈当前节点
            cur_node = cur_node->left;      //往左走到底
        } else {
            cur_node = treestack.top();
            treestack.pop();
            printf("inOrder_loop %d\n", cur_node->value);
            cur_node = cur_node->right;
        }
    }
    
}

void BinaryTree::postOrder_loop(BTreeNode *tree)
{
    if (tree == nullptr)
        return;
    
    std::stack<BTreeNode*> treestack;
    BTreeNode *cur_node = tree;
    while (cur_node || !treestack.empty())
    {
        if (cur_node) {
            treestack.push(cur_node);
            cur_node = cur_node->left;
        } else {
            //某个结点的左子树或左右子树已经访问完毕
            cur_node = treestack.top();
            treestack.pop();
            if (cur_node) {
                treestack.push(cur_node);
                treestack.push(nullptr);
                cur_node = cur_node->right;     //访问右子树
            } else {
                cur_node = treestack.top();
                treestack.pop();
                printf("postOrder_loop, %d\n", cur_node->value);
                cur_node = nullptr;     //以该结点为根的子树已经遍历完毕
            }
        }
        
    }
    
}

void BinaryTree::preOrder_recursion(BTreeNode *tree)
{
    if(tree) {
        printf("preOrder_recursion %d\n", tree->value);
        preOrder_recursion(tree->left);
        preOrder_recursion(tree->right);
    }
}

void BinaryTree::inOrder_recursion(BTreeNode *tree)
{
    if(tree) {
        inOrder_recursion(tree->left);
        printf("inOrder_recursion %d\n", tree->value);
        inOrder_recursion(tree->right);
    }
}

void BinaryTree::postOrder_recursion(BTreeNode *tree)
{
    if(tree) {
        postOrder_recursion(tree->left);
        postOrder_recursion(tree->right);
        printf("postOrder_recursion %d\n", tree->value);
    }
}

void BinaryTree::release_recursion(BTreeNode* &tree) {
    if (tree) {
        release_recursion(tree->left);
        release_recursion(tree->right);

        printf("delete %d\n", tree->value);
        delete tree;
        tree = nullptr;
    }
}

int main() {
    printf("binary tree start\n");

    BinaryTree btree;

    btree.addNode_loop(10);
    btree.addNode_loop(7);
    btree.addNode_loop(0);
    btree.addNode_loop(9);
    btree.addNode_loop(12);
    btree.addNode_loop(100);

    btree.preOrder_recursion(btree.mpTree);
    printf("\n");
    btree.inOrder_recursion(btree.mpTree);
    printf("\n");
    btree.postOrder_recursion(btree.mpTree);
    printf("\n");
    btree.preOrder_loop(btree.mpTree);
    printf("\n");
    btree.inOrder_loop(btree.mpTree);
    printf("\n");
    btree.postOrder_loop(btree.mpTree);
    printf("\n");
    btree.release_recursion(btree.mpTree);
    return 0;
}