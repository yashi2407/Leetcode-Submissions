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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* A, ListNode* B){
            return A->val>B->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(int i =0;i<lists.size();i++){
            if (lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(!pq.empty()){
            ListNode* current = pq.top();
            pq.pop();
            if(current->next){
                pq.push(current->next);
            }
            temp->next = current;
            temp=current;
        }
        return head->next;
    }
};