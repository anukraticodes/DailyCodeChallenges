class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        helper(num,target,0,"",0,0);
        return ans;
    }

    void helper(string s, int target, int i, const string& path, long eval, long residual){
        if(i==s.size()){
            if(eval==target){
                ans.push_back(path);
                return;
            }
        }

        string curr;
        long num=0;
        for(int j=i; j<s.size(); j++){
            if(j>i && s[i]=='0') return;
            curr+=s[j];
            num=num*10+s[j]-'0';
            if(i==0) helper(s,target,j+1, path+curr, num, num);
            else{
                helper(s,target,j+1,path + "+" + curr, eval + num, num);
                helper(s,target,j+1,path + "-" + curr, eval - num, -num);
                helper(s,target,j+1,path + "*" + curr, eval -residual + residual*num , residual*num);
            }
        }
    }
};