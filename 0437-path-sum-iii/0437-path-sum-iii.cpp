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
    int util(TreeNode* root, long long targetSum){
        if(root == NULL){
            return 0;
        }
        int count = 0;
        int left = util(root->left,targetSum-root->val);
        int right = util(root->right,targetSum-root->val);
        if(root->val == targetSum){
            count++;
        }
        count = count + left + right;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        return util(root,(long long)targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};