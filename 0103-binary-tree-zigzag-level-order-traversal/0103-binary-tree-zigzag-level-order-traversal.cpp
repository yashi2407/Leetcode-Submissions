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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int count=1;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> row;
            for(int i=0;i<n;i++){
                TreeNode* p=q.front();
                q.pop();
                row.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            if(count%2==0){
                reverse(row.begin(), row.end());
            }
            ans.push_back(row);
            count++;
        }
        return ans;
        
    }
};