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
    TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, map<int,int>&mp){
        if(preStart>preEnd || inStart > inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = mp[preorder[preStart]];
        int numsLeft = rootIndex - inStart;
        root->left = buildtree(preorder, inorder, preStart+1, preStart+numsLeft, inStart, rootIndex-1, mp);
        root->right = buildtree(preorder, inorder,preStart+numsLeft+1, preEnd, rootIndex+1, inEnd, mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return buildtree(preorder,inorder,0, preorder.size()-1, 0, inorder.size()-1,mp);
    }
};