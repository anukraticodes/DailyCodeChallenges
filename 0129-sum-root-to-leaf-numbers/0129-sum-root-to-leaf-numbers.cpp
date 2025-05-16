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

   void dfs(TreeNode* root, string current, vector<string>& result)
{
    if (!root) return;

    current += to_string(root->val); // change is local

    if (!root->left && !root->right)
        result.push_back(current);

    dfs(root->left, current, result);
    dfs(root->right, current, result);
}

    int sumNumbers(TreeNode* root) {
        int result=0;
        vector<string> v;
        string s="";
        dfs(root, s, v);
        for(auto st:v){
            result+=stoi(st);
        }
        return result;
    }
};