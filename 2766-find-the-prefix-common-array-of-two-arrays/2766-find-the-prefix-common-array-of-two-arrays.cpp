class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
          map<int, int> mp;
          int cnt=0;
          vector<int> ans;
          for(int i=0; i<A.size(); i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]!=B[i]){
                if(mp[A[i]]==2)cnt++;
                if(mp[B[i]]==2)cnt++;
            }
            else{
                 if(mp[A[i]]==2)cnt++;
            }
            ans.push_back(cnt);
          }
          return ans;
    }
};