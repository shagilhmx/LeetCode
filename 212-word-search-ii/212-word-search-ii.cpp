class node{
public:
    char c;
    unordered_map<char, node*> children;
    bool isEnd;
    string word;
    
    node(char c){
        this->c= c;
        isEnd= false;
        word="";
    }
};

class trie{
public:
    node* root;
    trie(){
        this->root= new node('\0');
    }
    
    void addWord(string s){
        node* curr= root;
        int n= s.length();
        for(int i=0; i<n; i++){
            char ch= s[i];
            if(curr->children[ch] == NULL){
                curr->children[ch]= new node(ch);
            }
            curr= curr->children[ch];
        }
        curr->isEnd= true;
        curr->word= s;
    }
};

class Solution {
public:
    trie t;
    
    void dfs(vector<vector<char>> &board, node* curr, int i, int j, vector<string> &ans){
        
        char c= board[i][j];
        if(c == '.' or curr->children[c] == nullptr)
            return;
        
        curr= curr->children[c];
        if(curr->isEnd == true){
            ans.push_back(curr->word);
            curr->isEnd= false;
        }
        
        c= board[i][j];
        board[i][j]= '.';
        
        if(i>0) 
            dfs(board, curr, i-1, j, ans);
        if(i<board.size()-1)
            dfs(board, curr, i+1, j, ans);
        if(j>0)
            dfs(board, curr, i, j-1, ans);
        if(j<board[0].size()-1)
            dfs(board, curr, i, j+1, ans);
        
        board[i][j]= c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m= board.size();
        int n= board[0].size();
        vector<string> ans;
        
        //insert all words into trie
        for(auto s: words){
            t.addWord(s);
        }
        //iterate over board to find if current word matches in the trie
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, t.root, i, j, ans);
            }
        }
        return ans;
    }
};