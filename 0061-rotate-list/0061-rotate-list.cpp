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
        ListNode* temp = head;
        // no element
        if(head == NULL){
            return head;
        }
        // one element
        if(head->next == NULL){
            return head;
        }
        int length = 0;
        while(temp){
            length++;
            temp = temp->next;
        }
        int newHeadIndex = length - (k%length);
        ListNode* newHead = head;
        ListNode* newTail = NULL;
        while(newHeadIndex>0){
            newTail = newHead;
            newHead = newHead->next;
            newHeadIndex--;
        }
        newTail->next = NULL;
        ListNode* tempNode = newHead;
        while(tempNode->next != NULL){
            tempNode = tempNode->next;
        }
        tempNode ->next = head;
        return newHead;
    }
};