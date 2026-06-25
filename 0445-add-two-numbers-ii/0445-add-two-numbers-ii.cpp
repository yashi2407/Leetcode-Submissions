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
    int getSize(ListNode* head){
        int count = 0;
        while(head!= NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* p = NULL;
        ListNode* q = head;
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* r = head->next;
        while(q!= NULL){
            q->next = p;
            p=q;
            q=r;
            if(r){
                r = r->next;
            }
        }
        return p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // check which list is bigger, amke it l1
        int s1 = getSize(l1);
        int s2 = getSize(l2);
        ListNode* head1 = NULL;
        ListNode* head2 = NULL;
        if(s1>s2){
            head1 = reverseList(l1);
            head2 = reverseList(l2);

        }
        else {
            head1 = reverseList(l2);
            head2 = reverseList(l1);
        }
        // now l1 is always bigger!
        int carry = 0;
        ListNode* temp = head1;
        ListNode* prevNode = NULL;
        while(head2!= NULL){
            int currentSum = temp->val+head2->val+ carry;
            temp->val = currentSum%10;
            carry = currentSum/10;
            prevNode = temp;
            temp=temp->next;
            head2=head2->next;
        }
        while(temp!= NULL){
            int currentSum = temp->val+ carry;
            temp->val = currentSum%10;
            carry = currentSum/10;
            prevNode = temp;
            temp=temp->next;
        }
        if(carry!=0){
            ListNode* lastNode = new ListNode(1);
            prevNode->next = lastNode;
        }
        return reverseList(head1);
    }
};