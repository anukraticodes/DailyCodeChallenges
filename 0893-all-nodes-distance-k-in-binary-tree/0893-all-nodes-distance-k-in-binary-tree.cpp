/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        dfs(root,m);
        queue<TreeNode*> q;
        q.push(target);
        vector<int> v;
        unordered_map<TreeNode*, bool> vis;
        while(!q.empty()){
            int l=q.size();
            while(l--){
         TreeNode* curr=q.front();
         q.pop();

         if(!k) v.push_back(curr->val);
         vis[curr]=true;

         if(curr->left&&!vis[curr->left]){
            q.push(curr->left);
         }

            if(curr->right&&!vis[curr->right]){
                q.push(curr->right);
            }

            if(m.find(curr)!=m.end()&&!vis[m[curr]]){
                q.push(m[curr]);
            }
         }
         k--;
         if(k<0)
         break;

        }
        return v;
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp){
        if(!root) return;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        dfs(root->left, mp);
        dfs(root->right, mp);
    }

};