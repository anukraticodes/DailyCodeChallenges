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

    void helper(TreeNode* root, int k, long long csum, int& cnt){
        if(root==NULL) return;
        csum+=root->val;
        if(csum==k) cnt++;
        
        
        helper(root->left, k, csum, cnt);
        
        helper(root->right, k, csum, cnt);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int cnt=0;
     helper(root, targetSum, 0, cnt);
     cnt += pathSum(root->left, targetSum);
    cnt += pathSum(root->right, targetSum);

    return cnt;
    }
};