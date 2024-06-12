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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;

        if(parent(root, x)==parent(root, y)) return false;

        int levelx, levely;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            if(node->val==x) levelx=level;
            else if(node->val==y) levely=level;
            q.pop();
            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});

        }
        if(levelx==levely) return true;
        return false;
    }

TreeNode* parent(TreeNode* root, int x){
if(root==NULL)
return NULL;

if((root->left&& root->left->val==x)||(root->right&& root->right->val==x))
return root;

TreeNode* leftParent = parent(root->left, x);
    if (leftParent) return leftParent;

     return parent(root->right, x);
}

};