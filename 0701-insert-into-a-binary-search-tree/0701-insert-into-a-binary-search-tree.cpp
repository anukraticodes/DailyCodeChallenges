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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        add(root, root, val, 0);
        return root;
    }

    void add(TreeNode* &par, TreeNode* &root, int val, bool dir){
        if(dir && !root){
            par->left=new TreeNode(val);
            return;
        }
        else if(!dir && !root){
            par->right=new TreeNode(val);
            return;
        }
        if(root->val<val){
            add(root, root->right, val, 0);
        }
        else add(root, root->left, val, 1);
    }
};