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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        maxGain(root, sum);
        return sum;
    }

    int maxGain(TreeNode* node, int& sum){
        if(node==NULL) return 0;
        int l=max(maxGain(node->left, sum), 0);
        int r=max(maxGain(node->right, sum), 0);
        int current=node->val+l+r;
        sum=max(sum, current);
        return node->val+max(l,r);
    }
};