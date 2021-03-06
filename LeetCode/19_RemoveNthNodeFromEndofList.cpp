/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 || head == NULL)
            return head;

        ListNode *first = head;
        ListNode **last = &head;
        
        for (int i = 1; i < n; i++){
            first = first->next;
        }

        while(first->next){
            last = &((*last)->next);
            first = first->next;
        }
        
        *last = (*last)->next;

        return head;
    }
};

int main()
{
    return 0;
}