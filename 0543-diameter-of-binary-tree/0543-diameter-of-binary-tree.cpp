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
        if(left+right>ans){
            ans = left+ right;
        }
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        util(root,ans);
        return ans;
    }
};