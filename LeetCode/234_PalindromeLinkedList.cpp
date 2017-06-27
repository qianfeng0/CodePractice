/**
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include <stdio.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        
        ListNode* once = head;
        ListNode* twice = head;
        while(twice->next && twice->next->next){
            twice = twice->next->next;
            once = once->next;
        }
        once->next = reverseList(once->next);
        ListNode* cur = once->next;
        while(cur){
            if (head->val != cur->val)
                return false;
            head = head->next;
            cur = cur->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* reHead = NULL;
        ListNode* cur = NULL;
        while(head){
            cur = head;
            head = head->next;
            cur->next = reHead;
            reHead = cur;
        }
        return reHead;
    }
};

class List
{
public:
    static void insert(ListNode* &head, ListNode* newlist){
        if (head == NULL){
            head = newlist;
            return;
        }
        ListNode* cur = head;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = newlist;
    }

    static void printList(ListNode* head){
        while(head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
};

int main()
{
    ListNode* list = NULL;
    List::insert(list, new ListNode(3));
    List::insert(list, new ListNode(4));
    List::insert(list, new ListNode(4));
    List::insert(list, new ListNode(3));
    List::printList(list);

    Solution solution;
    if (solution.isPalindrome(list))
        printf("is palindrome\n");
    else
        printf("is not palindrome\n");
    
    List::printList(list);
    return 0;
}