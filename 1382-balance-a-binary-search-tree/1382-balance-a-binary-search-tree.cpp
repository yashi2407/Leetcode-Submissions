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
    void inorderTraversal(TreeNode* root,vector<int>&getAllNodes){
        if(root == NULL){
            return;
        }
        inorderTraversal(root->left,getAllNodes);
        getAllNodes.push_back(root->val);
        inorderTraversal(root->right,getAllNodes);
    }
    TreeNode* createBST(vector<int>getAllNodes, int start, int end){
        // base condition
        if(start>end){
            return NULL;
        }
        int mid = (end-start)/2 + start;
        TreeNode* temp = new TreeNode(getAllNodes[mid]);
        temp->left = createBST(getAllNodes,start,mid-1);
        temp->right = createBST(getAllNodes,mid+1,end);

        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>getAllNodes;
        inorderTraversal(root,getAllNodes);
        TreeNode* newRoot = createBST(getAllNodes,0,getAllNodes.size()-1);
        return newRoot;
    }
};