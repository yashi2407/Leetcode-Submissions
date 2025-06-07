/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string hashValue(int val) {
        if (val == INT_MIN) return "#####";  // Reserved for null
        bool isNegative = val < 0;
        val = abs(val);
        string res = to_string(val);
        while (res.length() < 4)
            res = "0" + res;

        if (isNegative)
            res = "-" + res;
        else
            res = "+" + res;
        return res;
    }
    int unhashValue(const string& s) {
        if (s == "#####") return INT_MIN;  // Indicates null

        int sign = (s[0] == '-') ? -1 : 1;
        int val = stoi(s.substr(1));  // Convert rest
        return sign * val;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return hashValue(INT_MIN);
        }
        string res=hashValue(root->val);
        res+=serialize(root->left);
        res+=serialize(root->right);
        return res;
    }

    TreeNode* deserializeHelper(const string& data, int& index) {
        string token = data.substr(index, 5);
        index += 5;

        int val = unhashValue(token);
        if (val == INT_MIN) return nullptr;

        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(data, index);
        node->right = deserializeHelper(data, index);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));