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
    void solve(TreeNode* root, string currentPath,vector<string> &ans){
        if(root == NULL){
            return;
        }
        currentPath= currentPath + to_string(root->val) + "->";
        if(root->left == NULL && root->right == NULL){
            currentPath.erase(currentPath.size()-2);
            ans.push_back(currentPath);
            return;
        }
        solve(root->left, currentPath,ans);
        solve(root->right, currentPath,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string currentPath="";
        solve(root, currentPath, ans);
        return ans;
    }
};