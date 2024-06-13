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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> v;
        map<int, int> mp;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        while(!q.empty()){
          TreeNode* node=q.front().first;
          int level=q.front().second;
           mp[level]=node->val;
          q.pop();
          if(node->left) q.push({node->left, level+1});
          if(node->right) q.push({node->right, level+1});
        }
        for(auto i:mp){
            v.push_back(i.second);
        }
        return v;
    }
};