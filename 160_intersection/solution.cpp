/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<int> arrayA;
        vector<int> arrayB;
        ListNode *headA_ = headA;
        ListNode *headB_ = headB;
        ListNode *ret = NULL;
        if (headA==headB)
            return headA;

        arrayA.push_back(headA_->val);
        while(headA_->next!=NULL) {
            headA_=headA_->next;
            arrayA.push_back(headA_->val);
        }
        arrayB.push_back(headB_->val);
        while(headB_->next!=NULL) {
            headB_=headB_->next;
            arrayB.push_back(headB_->val);
        }
        int sizeA = arrayA.size();
        int sizeB = arrayB.size();
        bool Alarger = sizeA>=sizeB? true:false;

        while(sizeB!=sizeA) {
            if (Alarger) {
                headA = headA->next;
                sizeA--;
            } else {
                headB = headB->next;
                sizeB--;
            }
        }
        if (headA==headB)
            return headA;

        while(headA->next!=NULL && headB->next!=NULL) {
            headA = headA->next;
            headB = headB->next;
            if (headA==headB)
                return headA;
        }

        return ret;

    }
};