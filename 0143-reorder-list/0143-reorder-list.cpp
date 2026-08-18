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
        ListNode* reverseList(ListNode* head) {
        ListNode* prev= NULL;
        ListNode* current= head;
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* next = head->next;

        while(current!= NULL){
            current->next = prev;
            prev = current;
            current=next;
            if(next){
                next = next->next;
            }
        }
        return prev;
        
    }
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while(temp!= NULL){
            length++;
            temp = temp->next;
        }
        int splitIndex = (length+1)/2;
        ListNode* head2 = head;
        ListNode* prev = NULL;
        while(splitIndex!=0){
            prev = head2;
            head2 = head2->next;
            splitIndex--;
        }
        prev->next = NULL;
        ListNode *newHead = reverseList(head2);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != NULL) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }

    }
};