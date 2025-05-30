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

    int helper(TreeNode* node, int val){
        if(!node) return 0;
        int cnt=(node->val>=val)?1:0;
        val=max(val, node->val);
        return cnt+helper(node->left, val)+helper(node->right, val);
    }

    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};