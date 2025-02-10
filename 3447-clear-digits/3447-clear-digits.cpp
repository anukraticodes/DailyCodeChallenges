class Solution {
public:

    bool ischar(char c){
        return c>='a' && c<='z';
    }
    string clearDigits(string s) {
        stack<char> q;
        for(auto c:s){
            if(ischar(c)) {
                q.push(c);
                // cout<<c<<endl;
            }
            else q.pop();
        }
        string ans="";
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};