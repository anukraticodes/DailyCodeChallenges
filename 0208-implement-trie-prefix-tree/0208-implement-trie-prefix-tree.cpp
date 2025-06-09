class TrieNode {
public:
    bool isEnd = false;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:

TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(char c:word){
            if(!node->children[c])
            node->children[c]=new TrieNode();
            node=node->children[c];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(char c:word){
            if(!node->children.count(c)) return 0;
            node=node->children[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char c:prefix){
            if(!node->children.count(c)) return 0;
            node=node->children[c];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */