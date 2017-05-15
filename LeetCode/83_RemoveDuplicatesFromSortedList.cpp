/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode* last = head;
        ListNode* cur = head->next;
        while(cur){
            if(cur->val == last->val){
                cur = cur->next;
                delete last->next;
                last->next = cur;
            }
            else{
                last = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

void addNode(ListNode** list, int val){
    if(*list == NULL){
        *list = new ListNode(val);
    }
    else{
        ListNode* cur = *list;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new ListNode(val);
    }
    return;
}

void freeList(ListNode** list){
    ListNode* cur = NULL;
    while(*list){
        cur = *list;
        *list = (*list)->next;
        delete cur;
    }
    return;
}

void printList(ListNode* list){
    while(list){
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
    return;
}

int main(){
    Solution solution;
    ListNode* list = NULL;
    addNode(&list, 1);
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 2);

    ListNode* delList = solution.deleteDuplicates(list); 
    printList(delList);
    freeList(&delList);
    return 0;
}