class Node {
    char ch;
    Node[] link;
    boolean isEnd = false;
    
    Node(char ch) {
        this.ch = ch;
        this.link = new Node[26];
    }
}

class TrieOperations {
    Node root;
    
    TrieOperations() {
        root = new Node('\0');
    }
    
    public void insert(String word) {
        Node curr = root;
        for(int i=0;i<word.length();i++) {
            char c = word.charAt(i);
            if(curr.link[c - 'a'] == null) curr.link[c - 'a'] = new Node(c);
            curr = curr.link[c - 'a'];
        }
        curr.isEnd = true;
    }
}

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        TrieOperations trie = new TrieOperations();
        
        for(String word : wordDict) trie.insert(word);
        
        boolean[] dp = new boolean[s.length() + 1];
        char[] str = s.toCharArray();
        dp[0] = true;
        
        for(int i=0;i<str.length;i++) {
            if(!dp[i]) continue;
            
            int j = i;
            Node curr = trie.root;
            while(j < str.length && curr.link[str[j] - 'a'] != null) {
                curr = curr.link[str[j++] - 'a'];
                if(curr.isEnd) {
                    dp[j] = true;
                }
            }
        }
        return dp[str.length];
    }
}