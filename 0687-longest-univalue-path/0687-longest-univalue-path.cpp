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
    int util(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }
        int left = util(root->left,ans);
        int right = util(root->right,ans);
        if(root->left != NULL && root->val == root->left->val){
            left++;
        }
        else {
            left = 0;
        }
        if(root->right != NULL && root->val == root->right->val){
            right++;
        }
        else {
            right = 0;
        }
        ans = max(ans,left+right);
        return max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        util(root,ans);
        return ans;
    }
};