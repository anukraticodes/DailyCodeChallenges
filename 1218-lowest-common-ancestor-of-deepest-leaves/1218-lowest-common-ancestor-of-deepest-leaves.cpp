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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<pair<int, int>> last=bfs(root);
        int a=last.begin()->second;
        int b=last.rbegin()->second;
        return lca(root, a, b);
    }

    vector<pair<int, int>> bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<pair<int, int>>> v;
        int h=0;
        while(!q.empty()){
            int size=q.size();
            vector<pair<int, int>> st;
            for(int i=0; i<size; i++){
                auto curr=q.front();
                q.pop();
                st.push_back({h, curr->val});
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            v.push_back(st);
            h++;
        }
        return v.back();
    }

    TreeNode* lca(TreeNode* root, int& a, int &b){
        if(!root || root->val==a || root->val==b) return root;
        auto left=lca(root->left, a, b);
        auto right=lca(root->right, a, b);

        if(!left) return right;
        else if(!right) return left;
        return root;

    }
};