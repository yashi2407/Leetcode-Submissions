/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root==NULL){
            return root;
        }
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
            Node *prev = new Node(0);
            while(n!=0){
                Node* current = q.front();
                q.pop();
                n--;
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
                prev->next = current;
                prev = current;
            }
            prev->next = NULL;
        }
        return root;
    }
};