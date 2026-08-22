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
    void hasSum(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>&currentPath){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(targetSum - root->val == 0){
                currentPath.push_back(root->val);
                ans.push_back(currentPath);
                currentPath.pop_back();
            }
            return;
        }
        currentPath.push_back(root->val);
        hasSum(root->left,targetSum-root->val,ans,currentPath);
        hasSum(root->right,targetSum-root->val,ans,currentPath);
        currentPath.pop_back();
        return;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>currentPath;
        hasSum(root,targetSum,ans,currentPath);
        return ans;
    }
};