class Node{
    public:
    
    Node* links[26]={};
    bool contains(char c){
        return links[c-'a']!=NULL;
    }

    void put(char c, Node* node){
        links[c-'a']=node;
    }

    Node* next(char c){
        return links[c-'a'];
    }

};

class Trie{
    public:
    Node* root;

    Trie(){ root=new Node();}

    void insert(string& word){
        Node* node=root;
     for(char c: word){
    if(!node->contains(c)) node->put(c,new Node());
        node=node->next(c);
}    }

bool find(string& prefix){
    Node* node=root;
    for(char c:prefix){
        if(!node->contains(c)) return 0;
        node=node->next(c);
    }
    return 1;
}
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            Trie prefixTrie, suffixTrie;
            prefixTrie.insert(words[i]);
            string revWord=words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            for(int j=0; j<i; j++){
                if(words[j].size()>words[i].size()) continue;
                string prefixWord=words[j];
                string revPrefixWord=prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());
                if (prefixTrie.find(prefixWord) &&
                    suffixTrie.find(revPrefixWord)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};