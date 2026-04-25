class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if (!root) return 0;

        int temp = 0;
        int ans = 0;

        int left = solve(root->left, res);
        int right = solve(root->right, res);

        // height
        temp = max(left, right) + 1;

        // diameter through current node
        ans = left + right;

        // update result
        res = max(res, ans);

        // return height (NOT res)
        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};