class TrieNode {
    public:
    TrieNode* links[26];
    bool flag;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }
    
    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
};

class trieOperations {
    public:TrieNode* root;
    
    public:
        trieOperations() {
            root = new TrieNode();
        }
    
    void insert(string word) {
        TrieNode *node = root;
        
        for(int i=0;i<word.size();i++) {
            if(!node -> containsKey(word[i]))
                node -> put(word[i], new TrieNode());
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trieOperations trie;
        vector<string> res;
        
        for(auto& word : words)
            trie.insert(word);
        
        //use dfs to check weather the word is concatenated word or not.
        for(auto& s: words) {
            if(isConcatenated(s, trie.root, 0, 0))
                res.push_back(s);
        } 
        
        return res;
    }
    
    bool isConcatenated(string& word, TrieNode* root, int index, int sections) {
        if(index == word.size())
            return sections >= 2;
        
        TrieNode* cur = root;
        
        for (int i = index; i < word.length(); i++){
            char c = word[i];
            if (cur -> links[c - 'a']){
                cur = cur -> links[c - 'a'];
                if (cur -> flag && isConcatenated(word, root, i + 1, sections + 1)){
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};