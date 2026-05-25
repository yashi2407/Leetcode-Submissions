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
   struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap!
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i=0;i<lists.size();i++){
            if (lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        // now temp will move
        while(!pq.empty()){
            ListNode* nextNode = pq.top();
            pq.pop();
            temp->next = nextNode;
            if(nextNode->next){
                pq.push(nextNode->next);
            }
            temp = temp->next;
        }
        return newHead->next;
    }
};