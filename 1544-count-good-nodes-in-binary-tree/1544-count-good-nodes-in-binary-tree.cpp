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

    void helper(TreeNode* root, int& ans, vector<int>& curr){
        if(!root){
            return;
        }
        if(!curr.empty() && *max_element(curr.begin(), curr.end())<=root->val){
            ans++;
        }
        curr.push_back(root->val);
        if(root->left) helper(root->left, ans, curr);
        if(root->right) helper(root->right, ans, curr);
        curr.pop_back();
    }

    int goodNodes(TreeNode* root) {
        int ans=1;
        vector<int> curr;
        helper(root, ans, curr);
        return ans;
    }
};