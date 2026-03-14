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
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* prev = NULL;
        int carry = 0;

        while(p!= NULL && q!= NULL){
            int sum = p->val + q->val + carry;
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            // storing in l1 linkedList
            p->val = sum;
            prev = p;
            p = p->next;
            q = q->next;
            
        }
        // q is longer!
        if(q!= NULL){
            prev->next = q;
            p = q;

        }
        while(p!= NULL){
            int sum = p->val + carry;
            if(sum>9){
                sum = sum%10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            p->val = sum;
            prev = p;
            p = p->next;
        }
        // add in new node with val 1
        if(carry == 1){
            prev->next = new ListNode(1);
        }
        return l1;
    }
};