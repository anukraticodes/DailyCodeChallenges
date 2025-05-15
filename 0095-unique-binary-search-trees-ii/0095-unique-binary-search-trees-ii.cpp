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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        unordered_map<string, vector<TreeNode*>> dp;
        return helper(1, n, dp);
    }

    vector<TreeNode*> helper(int start, int end, unordered_map<string, vector<TreeNode*>>& dp){
        string key=to_string(start)+ "-"+to_string(end);
        if(dp.find(key)!=dp.end()) return dp[key];

        vector<TreeNode*> trees;
        if(start>end){
            trees.push_back(NULL);
            return trees;
        }

        for(int i=start; i<=end; i++){
            vector<TreeNode*> left=helper(start, i-1, dp);
            vector<TreeNode*> right=helper(i+1, end, dp);

            for(TreeNode* leftt:left){
                for(TreeNode* rightt:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftt;
                    root->right=rightt;
                    trees.push_back(root);
                }
            }
        }
        dp[key]=trees;
        return trees;
    }
};