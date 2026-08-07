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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return inorder(root, k, cnt);
    }

    int inorder(TreeNode* root, int k, int& cnt){
       if (!root) return -1;

        // Traverse Left Subtree
        int left = inorder(root->left, k, cnt);
        if (left != -1) return left; // 2. Propagate answer up

        // Visit Current Node
        cnt++; // 3. Increment counter for visited node
        if (cnt == k) return root->val;

        // Traverse Right Subtree
        return inorder(root->right, k, cnt);
    }
};