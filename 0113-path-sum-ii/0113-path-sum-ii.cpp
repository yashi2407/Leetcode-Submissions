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
    void util(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>&currentPath){
        if(root == NULL){
            return;
        }
        // leaf node
        if(root->left == NULL && root->right == NULL){
            if(root->val == targetSum){
                currentPath.push_back(root->val);
                ans.push_back(currentPath);
                currentPath.pop_back();
                return;
            }
        }
        currentPath.push_back(root->val);
        targetSum = targetSum-root->val;
        util(root->left,targetSum,ans,currentPath);
        util(root->right,targetSum,ans,currentPath);
        currentPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>currentPath;
        util(root,targetSum,ans,currentPath);
        return ans;
    }
};