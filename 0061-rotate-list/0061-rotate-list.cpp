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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        ListNode* q = head;
        ListNode* p = head;
        int size = 0;
        while(q!= NULL){
            size = size+1;
            p = q;
            q = q->next;
        }
        p->next = head; // make circular list!
        int newHead = size - (k%size);
        while (newHead--) head = head->next;
        ListNode* temp = head;
        while(size-1 !=0){
            temp = temp->next;
            size--;
        }
        temp->next = NULL;
        return head;

    }
};