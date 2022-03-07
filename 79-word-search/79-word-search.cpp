class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //dfs solution.
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {
        if(index >= word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || word[index] != board[i][j]) return false;
        
        board[i][j] = '#';
        
        bool ans = dfs(board, word, i+1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1);
        board[i][j] = word[index];
        
        return ans;
    }
};