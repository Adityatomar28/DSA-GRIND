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
    int solve(TreeNode* root,int count){
    if(!root) return 0;

    int ans = 0;
    if(root->left == nullptr && root->right == nullptr){
    ans = count;
    
    } 
    int left  = 1 + solve(root->left,count);
    int right = 1 + solve(root->right,count);

    return max(left,right);


    } 
    int maxDepth(TreeNode* root) {
    int count = 0;
    return solve(root,count);
    }
};
