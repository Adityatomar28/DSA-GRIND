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

class Codec {
public:

    void preorder(TreeNode* root, string &s) {
        if (root == nullptr) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* deserializeH(stringstream &ss) {
        string val;
        getline(ss, val, ',');

        if (val == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeH(ss);
        root->right = deserializeH(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeH(ss);
    }
};
