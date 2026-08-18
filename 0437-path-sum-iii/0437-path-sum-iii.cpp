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
    int util(TreeNode* root, int targetSum, long long currentSum){
        if(root == NULL){
            return 0;
        }
        int count = 0;
        currentSum+= root->val;
        if(currentSum == targetSum){
            count++;
        }
        count += util(root->left, targetSum, currentSum);
        count += util(root->right,targetSum, currentSum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        return util(root,targetSum,0) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};