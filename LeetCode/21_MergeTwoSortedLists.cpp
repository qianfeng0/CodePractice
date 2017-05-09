/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include "stdio.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addNOde(ListNode** list, int val){
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
}

void freeList(ListNode** list){
    ListNode* cur;
    while(*list){
        cur = *list;
        *list = (*list)->next;
        delete cur;
    }
}

void printfList(ListNode* list){
    while(list){
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode* cur = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main(){
    Solution solution;

    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    addNOde(&l1, 1);
    addNOde(&l1, 4);
    addNOde(&l1, 8);

    addNOde(&l2, 5);
    addNOde(&l2, 10);
    addNOde(&l2, 12);

    printfList(l1);
    printfList(l2);

    printfList(solution.mergeTwoLists(l1,l2));

    freeList(&l1);
    freeList(&l2);
    return 0;
}