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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        if(root){
            q.push({root,1});
        }
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            int offset = q.front().second;
            int currentWidth = q.back().second - q.front().second+1;
            ans=max(ans,currentWidth);
            for(int i=0;i<n;i++){
                auto [node, idx] = q.front(); q.pop();
                idx -= offset; // normalize to prevent overflow
                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }

        }
        return ans;
    }
};