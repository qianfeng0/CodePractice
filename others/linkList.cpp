#include <iostream>

struct listNode
{
    int value;
    listNode *nextNode;
    listNode(int v) : value(v), nextNode(nullptr){};
};

void addNode(listNode **pNode, int value)
{

    if (*pNode == nullptr)
    {
        *pNode = new listNode(value);
        return;
    }

    listNode *p = *pNode;
    while (p->nextNode)
    {
        p = p->nextNode;
    }
    p->nextNode = new listNode(value);
    return;
}

void deleteList(listNode **pNode)
{
    if (*pNode == nullptr)
    {
        return;
    }

    listNode *p = *pNode;
    listNode *temp;
    while (p)
    {
        temp = p;
        p = p->nextNode;
        delete temp;
    }
    *pNode = nullptr;
}

void printList(const listNode *pNode)
{
    while (pNode)
    {
        std::cout << pNode->value << " ";
        pNode = pNode->nextNode;
    }
    std::cout << std::endl;
}

void reverseList(listNode **ppHead)
{
    if (*ppHead == nullptr || (*ppHead)->nextNode == nullptr)
        return;

    listNode *reverseHead = nullptr;
    listNode *curNode = *ppHead;
    while (curNode != nullptr)
    {
        listNode *temp = curNode;
        curNode = curNode->nextNode;
        temp->nextNode = reverseHead;
        reverseHead = temp;
    }
    *ppHead = reverseHead;
}

int main()
{
    std::cout << "hello\n";

    listNode *list = nullptr;
    addNode(&list, 10);
    addNode(&list, 5);
    printList(list);
    reverseList(&list);
    printList(list);
    deleteList(&list);

    return 0;
}