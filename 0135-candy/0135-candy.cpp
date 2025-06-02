class Solution {
public:
    int candy(vector<int>& r) {
        // int cnt=r.size();
        if(r.size()==1) return 1;
        multiset<pair<int, int>> st;
        for(int i=0; i<r.size(); i++){
        st.insert({r[i], i});
        }
        vector<int> v(r.size(), 1);
        auto it=st.begin();
        it++;
        for(; it!=st.end(); it++){
            
            if(it->second==0){
                if(r[0]>r[1]) v[0]=1+v[1];
            }
            else if(it->second==r.size()-1){
                if(r[r.size()-1]>r[r.size()-2]) v[r.size()-1]=1+v[r.size()-2];
            }
            else{
                int i=it->second;
                if(r[i]>r[i-1] && r[i]>r[i+1])
                v[i]=1+max(v[i-1], v[i+1]);
                else if(r[i]>r[i+1]) v[i]=1+v[i+1];
                else if(r[i]>r[i-1]) v[i]=1+v[i-1];
            }
        }
        int sum=accumulate(v.begin(), v.end(), 0);
        return sum;
    }
};