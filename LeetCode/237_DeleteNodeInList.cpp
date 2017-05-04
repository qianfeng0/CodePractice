/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

void addNode (ListNode** head, int val){
    if(*head == NULL){
        *head = new ListNode(val);
    }
    else{
        ListNode* cur = *head;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new ListNode(val);
    }
}

void freeList(ListNode** head){
    ListNode* temp = NULL;
    while(*head){
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

void printfList(const ListNode* head){
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL)
            return;
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

int main(){
    ListNode* list = NULL;
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    addNode(&list, 4);
    addNode(&list, 5);
    printfList(list);

    Solution solution;
    solution.deleteNode(list);
    printfList(list);
    freeList(&list);
    return 0;
}