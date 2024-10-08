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
    bool helper(TreeNode* root, int targetSum, int sum) {
        if(root==NULL) return false;
        sum=sum+root->val;
        if(root->left==NULL&&root->right==NULL){
            if(sum==targetSum) return true;
            return false;
        }
        bool l=helper(root->left,targetSum,sum);
        bool r=helper(root->right, targetSum, sum);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root==NULL) return false;
        return helper(root, targetSum, 0);
    }
    
};