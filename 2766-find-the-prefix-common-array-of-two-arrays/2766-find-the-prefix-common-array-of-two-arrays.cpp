class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
          set<int> a;
          set<int> b;
          vector<int> ans;
          int cnt=0;
          for(int i=0; i<A.size(); i++){
            a.insert(A[i]);
            b.insert(B[i]);
            if(A[i]!=B[i]){
            if(a.contains(A[i]) && b.contains(A[i])) cnt++;
            if(a.contains(B[i]) && b.contains(B[i])) cnt++;
            }
            else{
                if(a.contains(A[i]) && b.contains(A[i])) cnt++;
            }
            ans.push_back(cnt);
          }
          return ans;
    }
};