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
    int ans=0;
    void helper(TreeNode* node, int val, bool flag){
        if(!node) return;
        ans=max(ans, val);
        if(flag==0){
            helper(node->right, val+1, 1);
            helper(node->left, 1, 0);
        }
        else{
            helper(node->left, val+1, 0);
            helper(node->right, 1, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        helper(root->left, 1, 0);
        helper(root->right, 1, 1);
        return ans;
    }
};