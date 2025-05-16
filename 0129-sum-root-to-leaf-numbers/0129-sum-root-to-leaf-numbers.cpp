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

    void dfs(TreeNode* root, int current, int& total) {
    if (!root) return;

    current = (current * 10 + root->val);

    if (!root->left && !root->right) {
        total = (total + current);
        return;
    }

    dfs(root->left, current, total);
    dfs(root->right, current, total);
}
    int sumNumbers(TreeNode* root) {
        int result=0;
        dfs(root, 0, result);
        return result;
    }
};