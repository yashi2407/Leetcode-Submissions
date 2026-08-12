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
        cout<<"left is"<<left<<endl<<"right is"<<right<<endl;
        ans = max(ans, (root->val + left + right));
        cout<<"ans now is"<<ans<<endl;
        int returnValue = root->val + max(left,right);
        cout<<"return value is"<<returnValue<<endl;
        return max(0,returnValue);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        util(root,ans);
        return ans;
    }
};