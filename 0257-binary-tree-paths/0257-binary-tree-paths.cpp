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
    void util(TreeNode* root,vector<string> &ans, string &currentPath){
        if (!root) return;
        int oldLen = currentPath.size();
        if (!root->left && !root->right){
            currentPath += to_string(root->val);
            ans.push_back(currentPath);
            currentPath.resize(oldLen);      
            return;
        }
        currentPath += to_string(root->val) + "->";
        if(root->left){
            util(root->left,ans,currentPath);
        }
        if(root->right){
            util(root->right,ans,currentPath);
        }
        currentPath.resize(oldLen);      
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string currentPath = "";
        util(root,ans, currentPath);
        return ans;
    }
};