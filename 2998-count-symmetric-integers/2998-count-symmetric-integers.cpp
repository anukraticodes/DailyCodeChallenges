class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low; i<=high; i++){
            string s=to_string(i);
            if(s.size()%2==0){
                string r=s.substr(0, s.size()/2);
                string t=s.substr(s.size()/2, s.size()/2);
                int j=0, k=0, sum1=0, sum2=0;
                while(j<r.size() && k<t.size()){
                    sum1+=r[j]-'0';
                    sum2+=t[k]-'0';
                    j++,k++;
                }
                if(sum1==sum2)cnt++;
            }
        }
        return cnt;
    }
};