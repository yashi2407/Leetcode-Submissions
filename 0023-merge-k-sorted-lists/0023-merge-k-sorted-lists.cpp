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
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(
    [](ListNode* a, ListNode* b) { return a->val > b->val; });

        // push all the first modes in the min heap
        for(int i = 0;i<lists.size();i++){
            if (lists[i]) pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(pq.size()>0){
          ListNode* currentNode = pq.top();
          pq.pop();
          temp->next = currentNode;
          temp = temp->next;
          if(currentNode ->next){
            pq.push(currentNode->next);
          }
        }
        return dummy->next;
    }
};