class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> st;
        for (ListNode* t = head; t != nullptr; t = t->next) st.push(t);

        ListNode* C1 = head;

        while (C1) {
            ListNode* C2 = st.top(); 
            st.pop();
            ListNode* nextElement = C1->next;
            // If we've met/crossed the middle (odd/even), terminate and stop.
            if (C2 == C1) {                 // odd length: middle node
                C1->next = nullptr;
                break;
            }
            if (C2 == nextElement) {        // even length: two middle nodes
                C1->next = C2;
                C2->next = nullptr;
                break;
            }

            // Normal weave: C1 -> C2 -> nextElement
            C1->next = C2;
            C2->next = nextElement;
            C1 = nextElement;
        }
    }
};
