string findShortestRoot(const unordered_set<string>& rootSet, const string& word) {
    for (int i = 1; i <= word.length(); ++i) {
        string prefix = word.substr(0, i);
        if (rootSet.find(prefix) != rootSet.end()) {
            return prefix;
        }
    }
    return word; 
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
       
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        istringstream iss(sentence);
        string word, result;
        bool firstWord = true;
        
        while (iss >> word) {
            if (!firstWord) {
                result += " ";
            }
            result += findShortestRoot(rootSet, word);
            firstWord = false;
        }
        
        return result;
    }
};