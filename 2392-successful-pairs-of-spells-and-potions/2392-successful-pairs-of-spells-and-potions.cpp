class Solution {
public:
 int helper(vector<int>& potions, long long success, int spell){
        int l=0, r=potions.size()-1, ind=potions.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if((long long)spell*(long long)potions[mid]>=success){
                ind=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ind;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs(spells.size());
        sort(potions.begin(), potions.end());
        for(int i=0; i<spells.size(); i++){
            int ind=helper(potions, success, spells[i]);
            pairs[i]=potions.size()-ind;
        }
        return pairs;
    }
};