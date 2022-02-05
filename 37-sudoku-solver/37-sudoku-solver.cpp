class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    
    bool helper(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++) {
            for(int col=0;col<board[0].size();col++) {
                if(board[row][col] == '.') {
                    
                    for(char tryOut = '1';tryOut <= '9';tryOut++) {
                        if(isValid(board, row, col, tryOut)) {
                            board[row][col] = tryOut;
                            
                            if(helper(board)) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, int tryOut) {
        for(int i=0;i<9;i++) {
            if(board[i][col] == tryOut) return false;
            
            if(board[row][i] == tryOut) return false;
            
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == tryOut) return false;
        }
        
        return true;
    }
};