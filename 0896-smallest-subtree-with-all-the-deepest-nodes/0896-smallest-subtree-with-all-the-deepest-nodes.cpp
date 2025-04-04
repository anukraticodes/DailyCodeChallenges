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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }

    pair<TreeNode*, int> dfs(TreeNode* root){
        if(!root) return {nullptr, 0};
        auto l=dfs(root->left);
        auto r=dfs(root->right);

        if(l.second>r.second) return {l.first, l.second+1};
        else if(r.second>l.second) return {r.first, r.second+1};

        else return {root, l.second+1};
    }
};