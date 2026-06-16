struct Trie{
    bool isEnd;
    Trie* children[26];

    Trie(){
        isEnd=0;
        for(int i=0; i<26; i++) children[i]=nullptr;
    }
};

class WordDictionary {
public:
Trie* root=new Trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie* curr=root;
        for(auto ch:word){
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a']=new Trie();
            }
            curr=curr->children[ch-'a'];
        }
        curr->isEnd=1;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Trie* root, string& word, int ind){
        if(ind==word.size()) return root->isEnd;

        if(word[ind]=='.'){
            for(int i=0; i<26; i++){
                if(root->children[i]){
                if(dfs(root->children[i], word, ind+1)) return 1;
                }
            }
            return 0;
        }

        if(root->children[word[ind]-'a']){
            return dfs(root->children[word[ind]-'a'], word, ind+1);
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */