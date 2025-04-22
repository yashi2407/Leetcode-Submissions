/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode *p= q.back();
            ans.push_back(p->val);
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode * s= q.front();
                q.pop();
                if(s->left!=NULL){
                    q.push(s->left);
                }
                if(s->right!=NULL){
                    q.push(s->right);
                }

            }
        }
        return ans;
    }
};