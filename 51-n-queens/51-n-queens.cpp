class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        
        string s(n, '.');
        
        for(int i=0;i<n;i++) board[i] = s;
        
        helper(0, board, n);
        
        return ans;
    }
    
    void helper(int col, vector<string>& board, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(col + 1, board, n);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int tempRow = row;
        int tempCol = col;
        
        while(tempRow >= 0 && tempCol >= 0) if(board[tempRow--][tempCol--] == 'Q') return false;
        
        tempCol = col;
        tempRow = row;
         
        while(tempCol >= 0) if(board[tempRow][tempCol--] == 'Q') return false;
        
        tempCol = col;
        tempRow = row;
        
        while(tempCol >= 0 && tempRow < n) if(board[tempRow++][tempCol--] == 'Q') return false;
        
        return true;
    }
};