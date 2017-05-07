/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* const list = new ListNode(l1->val + l2->val);
        ListNode* cur = list;

        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL || l2 != NULL)
        {
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum);
            cur = cur->next;
        }

        cur = list;
        while(cur)
        {
            if(cur->val >= 10)
            {
                cur->val -= 10;
                if(cur->next)
                {
                    cur->next->val++;
                }
                else
                {
                    cur->next = new ListNode(1);
                }
            }
            cur = cur->next;
        }
        return list;
    }
};

int main()
{
    //init list1 and list2
    ListNode *list1, *list2;
    list1 = new ListNode(2);
    list2 = new ListNode(5);

    ListNode *cur;
    cur = list1;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(3);

    cur = list2;
    cur->next = new ListNode(6);
    cur = cur->next;
    cur->next = new ListNode(8);

    //solution
    Solution solution;
    ListNode* listAdd = solution.addTwoNumbers(list1, list2);

    //print out
    cur = listAdd;
    while(cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");

    //delete
    while(list1)
    {
        cur = list1;
        list1 = list1->next;
        delete(cur);
    }
    while(list2)
    {
        cur = list2;
        list2 = list2->next;
        delete(cur);
    }

    while(listAdd)
    {
        cur = listAdd;
        listAdd = listAdd->next;
        delete(cur);
    }
    return 0;
}