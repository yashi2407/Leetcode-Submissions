/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* prev = nullptr;
        while(temp1 != NULL && temp2!= NULL){
            int sum = temp1->val + temp2->val + carry;
            temp1->val = sum%10;
            carry = sum/10;
            prev = temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        // if l1 is smaller, attach prev to temp2 and continue
        if (!temp1 && temp2) {
            prev->next = temp2;
            temp1 = temp2;   // continue processing carry on this attached tail
        }
        while (temp1) {
            int sum = temp1->val + carry;
            temp1->val = sum % 10;
            carry = sum / 10;

            prev = temp1;
            temp1 = temp1->next;
        }
        // if carry still exists, append new node
        if (carry) {
            prev->next = new ListNode(carry);
        }

        return l1;
    }
};