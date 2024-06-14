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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int start, end;
        start=0;
        end=nums.size()-1;
        return helper(nums, start, end);
    }

    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start>end)
        return NULL;
        TreeNode* root;
        int mid=(start+end)/2;
        
        root= new TreeNode(nums[mid]);
        root->left=helper(nums, start,mid-1);
        root->right=helper(nums, mid+1, end);
        
        return root;
    }
};