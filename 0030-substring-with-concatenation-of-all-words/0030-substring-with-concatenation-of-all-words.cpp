class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> mp;
        for(auto it:words){
            mp[it]++;
        }
        vector<int> ans;
        int len = words[0].size();
int total = words.size();

for(int start = 0; start < len; start++){
    int left = start, count = 0;
    unordered_map<string,int> seen;

    for(int right = start; right + len <= s.size(); right += len){
        string word = s.substr(right, len);

        if(mp.count(word)){
            seen[word]++;
            count++;

            while(seen[word] > mp[word]){
                string leftWord = s.substr(left, len);
                seen[leftWord]--;
                left += len;
                count--;
            }

            if(count == total){
                ans.push_back(left);
            }
        } else {
            seen.clear();
            count = 0;
            left = right + len;
        }
    }
}

        return ans;
    }
};