struct Node {
    Node * links[26];
    int flag = false;
    vector<string> suggestion;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    Node * get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node * node) {
        links[ch - 'a'] = node;
    }
    
    bool isEnd() {
        return flag;
    }
    
    void setEnd() {
        flag = true;
    }
};

class Trie {
    private:
        Node * root;

    public:
        Trie() {
          root = new Node();
        }

    void insert(string word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node -> containsKey(word[i]))
                node -> put(word[i], new Node());
            node = node -> get(word[i]);
            
            if(node -> suggestion.size() < 3)
                node -> suggestion.push_back(word);
        }
    }

    vector<string> countWordsStartingWith(string & word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node -> containsKey(word[i]))
                node = node -> get(word[i]);
            else
                return {};
        }
        return node -> suggestion;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        for(auto word : products)
            trie.insert(word);
        
        string sub = "";
        for(auto ch : searchWord) {
            sub += ch;
            ans.push_back(trie.countWordsStartingWith(sub));
        }
        
        return ans;
    }
};