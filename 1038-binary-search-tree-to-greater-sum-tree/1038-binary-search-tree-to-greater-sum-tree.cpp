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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> st;
        set<TreeNode*> s;
        int sum=0;
        st.push(root);
        s.insert(root);
        while(!st.empty()){
            TreeNode* node=st.top();
        
            if(node->right && !s.count(node->right)){
                st.push(node->right);
                s.insert(node->right);
            }
            else{
                sum+=node->val;
                node->val=sum;
                st.pop();
                if(node->left) st.push(node->left);
            }
        }
        return root;
    }
};