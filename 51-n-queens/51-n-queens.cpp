class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        
        string s(n, '.');
        
        for(int i=0;i<n;i++) board[i] = s;
        
        vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
        helper(0, board, leftRow, upperDiagonal, lowerDiagonal, n);
        
        return ans;
    }
    
    void helper(int col, vector<string>& board, vector<int> leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                helper(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
};