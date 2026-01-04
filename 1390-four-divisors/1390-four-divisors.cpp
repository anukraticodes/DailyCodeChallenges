class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            set<int> temp;
            helper(temp, it);
            if(temp.size()==4){
                int add=0;
                for(auto it:temp){
                  add+=it;
                }
                ans+=add;
            }
        }
        return ans;
    }

    void helper(set<int>& div, int a){
        div.insert(1);
        div.insert(a);
        for(int i=2; i*i<=a; i++){
            if(a%i==0){
                div.insert(i);
                div.insert(a/i);
            }
        }
    }
};