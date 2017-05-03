/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addNode(ListNode** list, int val)
{
    if(*list == NULL){
        *list = new ListNode(val);
    }
    else{
        ListNode *cur = *list;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new ListNode(val);
    }
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        while(even && even->next){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;    
    }
};

int main(){
    ListNode* list = NULL;
    addNode(&list, 1);
    addNode(&list, 2);
    addNode(&list, 3);
    addNode(&list, 4);
    addNode(&list, 5);

    Solution solution;
    list = solution.oddEvenList(list);
    return 0;
}