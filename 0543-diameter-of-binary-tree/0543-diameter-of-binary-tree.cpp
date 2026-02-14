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
        int left = 0; int right = 0;
        left = util(root->left,ans);
        right = util(root->right,ans);

        int height = 1 + max(left,right);
        ans = max(ans, left + right);

        return height;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        util(root, ans);
        return ans;
    }
};