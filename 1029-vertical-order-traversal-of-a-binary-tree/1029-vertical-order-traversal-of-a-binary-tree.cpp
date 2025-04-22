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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        if(root != NULL){
            q.push({root,{0,0}});
        }
        map<int, map<int, multiset<int>>> nodes;
        while(!q.empty()){
            TreeNode* parent = q.front().first;
            int parentRow = q.front().second.first;
            int parentCol = q.front().second.second;
            nodes[parentCol][parentRow].insert(parent->val);
            q.pop();
            if(parent->left){
                int leftChildRow = parentRow+1;
                int leftChildCol = parentCol -1;
                q.push({parent->left,{leftChildRow,leftChildCol}});
            }
            if(parent->right){
                int rightChildRow = parentRow+1;
                int rightChildCol = parentCol+1;
                q.push({parent->right,{rightChildRow,rightChildCol}});
            }
        }

        vector<vector<int>> result;
        for (auto& columnEntry : nodes) {
            int columnIndex = columnEntry.first;
            auto& rowsInColumn = columnEntry.second;
            vector<int> columnValues;
            for (auto& rowEntry : rowsInColumn) {
                int rowIndex = rowEntry.first;
                auto& nodeValues = rowEntry.second;
                for (int value : nodeValues) {
                    columnValues.push_back(value);
                }
            }

            result.push_back(columnValues);
        }
        return result;
        
    }
};