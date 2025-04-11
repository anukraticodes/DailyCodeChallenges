class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low; i<=high; i++){
            string s=to_string(i);
            if(s.size()%2==0){
                int j=0, k=s.size()-1, sum1=0, sum2=0;
                while(j<k){
                    sum1+=s[j]-'0';
                    sum2+=s[k]-'0';
                    j++,k--;
                }
                if(sum1==sum2)cnt++;
            }
        }
        return cnt;
    }
};