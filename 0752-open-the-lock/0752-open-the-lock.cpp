class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans=INT_MAX;
        vector<bool> vis(10000, 0);
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis[0]=1;
        unordered_set<string> st;
        for(auto it:deadends) st.insert(it);
        if(st.count("0000")) return -1;
     
        while(!q.empty()){
            auto [s, dep]=q.front();
            q.pop();
            if(s==target) {ans=dep;break;}
            for(int i=0; i<4; i++){
                int curr=s[i]-'0';
                int add1, add2;
                if(curr!=9) add1=curr+1; else add1=0;
                if(curr!=0) add2=curr-1; else add2=9;
                string a1=s, a2=s;
                a1[i]=add1+'0';
                a2[i]=add2+'0';
                if(!vis[stoi(a1)] && !st.count(a1)){vis[stoi(a1)]=1; q.push({a1, dep+1});}
                if(!vis[stoi(a2)] && !st.count(a2)) {vis[stoi(a2)]=1;q.push({a2, dep+1});}
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};