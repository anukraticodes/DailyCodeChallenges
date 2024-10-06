class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
       auto helper=[](const string& s){
        vector<string> words;
        string word="";
        for(int i=0; i<s.size(); i++){
            
            if(s[i]==' '){
                words.push_back(word);
                word="";
            }
            else{
                word+=s[i];
            }
        }
        if(word!="") words.push_back(word);
        return words;
       };
       vector<string> words1= helper(s1);
       vector<string> words2=helper(s2);
       if(words1.size()<words2.size()) swap(words1, words2);
       int start=0, end=0;
       int n1=words1.size(), n2=words2.size();
       while(start<n2 && words1[start]==words2[start]) start++;
       while(end<n2 && words1[n1-1-end]==words2[n2-1-end]) end++;
       return start+end>=n2;
}
};