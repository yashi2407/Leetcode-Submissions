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
    bool checkSubTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if((root == NULL && subRoot!= NULL ) || (root!= NULL && subRoot == NULL) || (root->val != subRoot->val)){
            return false;
        }
        
        bool left = checkSubTree(root->left,subRoot->left);
        bool right = checkSubTree(root->right,subRoot->right);
        return (root->val == subRoot ->val) && (left && right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL) {
            return true;
        }

        if (root == NULL) {
            return false;
        }
        return checkSubTree(root,subRoot) || isSubtree(root->right , subRoot) || isSubtree(root->left,subRoot);
    }
};