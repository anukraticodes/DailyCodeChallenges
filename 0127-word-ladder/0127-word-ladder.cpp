class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(word==endWord) return dis;
            for(int i=0; i<word.size(); i++){
                char ori=word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word, dis+1});
                        st.erase(word);
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};