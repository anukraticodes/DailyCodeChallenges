class Solution {
public:
    string repeatLimitedString(string s, int r) {
        // map<char, int>> mp;
        // for(int i=0; i<s.size(); i++){
        //     mp[s[i]]++;
        // }
        vector<int> freq(26,0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        priority_queue<pair<char,int>> pq;
        for(int i=0; i<26; i++){
            if(freq[i]!=0){
                pq.push({i+'a', freq[i]});
            }
        }
         string result = "";

    while (!pq.empty()) {
        auto [ch, f] = pq.top();
        pq.pop();
        int count = min(f, r);
        result.append(count, ch);
        f -= count;

        
        if (f > 0) {
            
            if (pq.empty()) break; 

            auto [nextCh, nextF] = pq.top();
            pq.pop();

            
            result += nextCh;
            nextF--;

           
            if (nextF > 0) {
                pq.push({nextCh, nextF});
            }

            
            pq.push({ch, f});
        }
    }

    return result;

    }
};