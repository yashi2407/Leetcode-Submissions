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
        auto cmp = [](ListNode *a, ListNode * b){
            return a->val>b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        // putting the first elements in the heap
        for(int i = 0;i<lists.size();i++){
            if (lists[i]) { //  only push non-null heads else cpm function will throw an error
                pq.push(lists[i]);
            }
        }
        // dummy node as head for the new list
        ListNode * head = new ListNode(0);
        ListNode * temp = head;
        while(!pq.empty()){
            ListNode* currentNode = pq.top();
            pq.pop();
            if(currentNode->next){
                pq.push(currentNode->next);
            }
            temp->next = currentNode;
            temp = temp->next;
        }
        return head->next;

    }
};