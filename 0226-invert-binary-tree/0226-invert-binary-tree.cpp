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
    void helper(TreeNode* root){
    if(!root) return;
    
    if(root->left && root->right){
        TreeNode* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    else if(root->left){
        root->right=root->left;
        root->left=nullptr;
    }
    else{
        root->left=root->right;
        root->right=nullptr;
    }
    helper(root->left);
    helper(root->right); 
} 

TreeNode* invertTree(TreeNode* A) {
    helper(A);
    return A;
}
};