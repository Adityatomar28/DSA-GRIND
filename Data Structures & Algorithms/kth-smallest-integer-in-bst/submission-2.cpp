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
    int count = 0;

    int solve(TreeNode* root, int k) {

        if (!root)
            return -1;

        // Left
        int left = solve(root->left, k);

        if (left != -1)
            return left;

        // Root
        count++;

        if (count == k)
            return root->val;

        // Right
        return solve(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        return solve(root, k);
    }
};
