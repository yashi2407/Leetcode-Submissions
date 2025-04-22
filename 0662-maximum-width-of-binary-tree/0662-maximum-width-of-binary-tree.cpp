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
        queue<pair<TreeNode*,int>> q;
        if(root){
            q.push({root,1});
        }
        long long maxWidth = 1;
        while(!q.empty()){
            if(q.size()>=2){
                long long currentWidth = q.back().second - q.front().second + 1;
                maxWidth = max(maxWidth,currentWidth);
            }
            long long n = q.size();
            for(long long i=0;i<n;i++){
                TreeNode* node = q.front().first;
                long long currentIndex = q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left,2*currentIndex+1});
                }
                if(node->right){
                    q.push({node->right,2*currentIndex+2});
                }  
            }
        }
        return maxWidth;
    }
};