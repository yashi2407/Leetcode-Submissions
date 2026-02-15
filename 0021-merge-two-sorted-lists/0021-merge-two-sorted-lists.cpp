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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        ListNode* temp = NULL;
        ListNode* newHead = NULL;
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        // list two's element will become new head
        if(list1->val > list2->val){
            newHead = list2;
            node2 = node2->next;
            temp = list2;
        }
        else{
            newHead = list1;
            node1 = node1->next;
            temp = list1;
        }

        while(node1!=NULL && node2 != NULL){
            // node 2 will come now
            if(node1->val >= node2->val){
                temp->next = node2;
                temp = temp->next;
                node2= node2->next;
            }
            else{
                temp->next = node1;
                temp = temp->next;
                node1= node1->next;
            }
        }
        while(node1 != NULL){
            temp->next = node1;
            temp = temp->next;
            node1= node1->next;
        }
        while(node2 != NULL){
            temp->next = node2;
            temp = temp->next;
            node2= node2->next;
        }
        return newHead;
    }
};