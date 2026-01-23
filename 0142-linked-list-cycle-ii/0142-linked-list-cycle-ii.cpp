/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * p = head;
        ListNode * q = head;
        ListNode *entry = head;
        while(q!=NULL && q->next !=NULL)
        {
            p = p->next;
            q = q->next->next;
            if(p==q){
                break;
            }
        }
        if(q == NULL || q->next == NULL){
            return NULL;
        }
        while(entry != p){
            entry = entry->next;
            p = p->next;
        }
        return entry;
    }
};