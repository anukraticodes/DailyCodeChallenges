class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        bt(ans, temp, nums);
        return ans;
    }

    void bt(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums){
        if(temp.size()==nums.size()){ ans.push_back(temp); return;}
    
            for(int i=0; i<nums.size(); i++){
                if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
            continue; 
        }
                temp.push_back(nums[i]);
                bt(ans, temp, nums);
                temp.pop_back();
            }
        
    }
};