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
vector<int> v;
    vector<int> rightSideView(TreeNode* root) {
        int lvl=0;
        helper(root, lvl);
        return v;
    }

    void helper(TreeNode* root, int level){
        if(!root) return;
        if(level==v.size()) v.push_back(root->val);

        helper(root->right,level+1 );
        helper(root->left, level+1);
    }
};