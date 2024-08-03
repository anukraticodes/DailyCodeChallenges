class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001]={0}, M=-1;
        for(int i=0; i<target.size(); i++){
            int x=target[i], a=arr[i];
            freq[x]++;
            freq[a]--;
            M=max({M, x, a});

        }
        for(int x=1; x<=M; x++){
            if(freq[x]!=0) return 0;
        }
        return 1;
    }
};