struct Node {
  Node * links[26];
  bool flag = false;
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void setEnd() {
    flag = true;
  }
  int isEnd() {
    return flag;
  }
};

class Trie {
  private:
    Node * root;

  public:
    /** Initialize your data structure here. */
    Trie() {
      root = new Node();
    }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node -> containsKey(word[i])) {
        node -> put(word[i], new Node());
      }
      node = node -> get(word[i]);
    }
    node -> setEnd();
  }

  bool countWordsStartingWith(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
      } else {
        return false;
      }
    }
    return true;
  }
};

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        Trie obj;
        obj.insert(s);
        
        int count = 0;
        for(auto word : words)
            if(obj.countWordsStartingWith(word))
                count++;
        
        return count;
    }
};