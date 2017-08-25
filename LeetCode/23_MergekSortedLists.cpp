/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {

    class cmp
    {
    public:
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode* p : lists){
            if (p != NULL){
                pq.push(p);
            }
        }

        if (pq.empty())
            return NULL;
        
        ListNode* res = pq.top();
        pq.pop();
        ListNode* tail = res;
        if (tail->next){
            pq.push(tail->next);
        }

        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;

            if (tail->next){
                pq.push(tail->next);
            }
        }

        return res;
    }
};




int main()
{
    return 0;
}