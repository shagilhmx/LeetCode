class Solution {
struct Node {
    char c;
    int ends;
    Node *link[26];
    string word;
};
    
    struct Node *getNode(char ch) {
        Node *newNode = new Node;
        newNode -> c = ch;
        newNode -> ends = 0;
        newNode -> word = "";
        for(int i=0;i<26;i++) newNode -> link[i] = NULL;
        
        return newNode;
    }
    
    Node *root = getNode('/');
    
    void insert(string s) {
        Node *currNode = root;
        int index, i = 0;
        
        while(s[i]) {
            index = s[i] - 'a';
            if(currNode -> link[index] == NULL) currNode -> link[index] = getNode(s[i]);
            
            currNode = currNode -> link[index];
            i++;
        }
        currNode -> ends = 1;
        currNode -> word = s;
    }
    
    void solve(vector<vector<char>>& board, int i, int j, int n, int m, vector<string>& ans, Node *curr) {
        int index = board[i][j] - 'a';
        if(board[i][j] == '#' || curr -> link[index] == NULL) return;
        
        curr = curr -> link[index];
        if(curr -> ends > 0) {
            ans.push_back(curr -> word);
            curr -> ends -= 1;
        }
        
        char ch = board[i][j];
        board[i][j] = '#';
        
        if(i > 0) solve(board, i - 1, j, n, m, ans, curr);
        if(i < n - 1) solve(board, i + 1, j, n, m, ans, curr);
        if(j > 0) solve(board, i, j - 1, n, m, ans, curr);
        if(j < m - 1) solve(board, i, j + 1, n, m, ans, curr);
        
        board[i][j] = ch;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<words.size();i++) insert(words[i]);
        
        vector<string> ans;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                solve(board, i, j, n, m, ans, root);
            }
        }
        return ans;
    }
};