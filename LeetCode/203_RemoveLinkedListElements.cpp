/**
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
        if (head == NULL){
            head = newNode;
        }
        else{
            ListNode* cur = head;
            while(cur->next)
                cur = cur->next;
            cur->next = newNode;
        }
    }

    static void delList(ListNode* &head)
    {
        ListNode* temp = NULL;
        while(head){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    static void printList(ListNode *head)
    {
        while(head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
};
/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        if (head == NULL)
            return NULL;
        
        ListNode* cur = head->next;
        ListNode* pre = head;
        while(cur){
            if (cur->val == val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head;
    }
};
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        while (cur->next){
            if (cur->next->val == val){
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else{
                cur = cur->next;
            }
        }
        if (head->val == val){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        return head;
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

    list = solution.removeElements(list, 6);
    List::printList(list);
    List::delList(list);
    return 0;
}