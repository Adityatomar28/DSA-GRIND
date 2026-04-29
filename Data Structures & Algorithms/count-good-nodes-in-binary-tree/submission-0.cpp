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
    int solve(TreeNode*root,int prev){
    if(!root) return 0;

    int count = 0;

    if(root->val >= prev){
    count = 1;
    prev = root->val;
    }

    count += solve(root->left,prev);
    count += solve(root->right,prev);
    return count;

    }
    int goodNodes(TreeNode* root) {
  
    return solve(root,root->val);
    }
};
