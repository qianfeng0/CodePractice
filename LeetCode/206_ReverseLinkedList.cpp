/**
Reverse a singly linked list.
*/

#include <stdio.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class List 
{
public:
    static void insert(ListNode* &head, ListNode* newNode)
    {
        if (head == NULL)
            head = newNode;
        else{
            ListNode *cur = head;
            while(cur->next){
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }

    static void delList (ListNode* &head)
    {
        ListNode *temp = NULL;
        while(head){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    static void printList(ListNode* head)
    {
        while(head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reversHead = NULL;
        ListNode *cur = NULL;
        while (head){
            cur = head;
            head = head->next;
            cur->next = reversHead;
            reversHead = cur;
        }
        return reversHead;
    }
};

int main()
{
    Solution solution;
    ListNode *list = NULL;
    List::insert(list, new ListNode(1));
    List::insert(list, new ListNode(2));
    List::insert(list, new ListNode(6));
    List::insert(list, new ListNode(3));
    List::insert(list, new ListNode(4));
    List::insert(list, new ListNode(5));
    List::insert(list, new ListNode(6));

    list = solution.reverseList(list);
    List::printList(list);
    List::delList(list);
    return 0;
}