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
    
    void helper(TreeNode* root, string& s){
        if(!root->left && !root->right){
            s+=to_string(root->val);
            s+="-";
            return;
        }
        if(root->left) helper(root->left, s);
        if(root->right) helper(root->right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return 1;
        string s1="", s2="";
        helper(root1, s1);
        helper(root2, s2);
        return s1==s2;
    }
};