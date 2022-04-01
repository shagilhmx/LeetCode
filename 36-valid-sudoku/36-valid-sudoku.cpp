class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for each rows.
        for(int i=0;i<9;i++) {
            unordered_set<char> set;
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') continue;
                if(set.find(board[i][j]) != set.end())
                    return false;
                set.insert(board[i][j]);
            }
        }
        
        //for each cols.
        for(int i=0;i<9;i++) {
            unordered_set<char> set;
            for(int j=0;j<9;j++) {
                if(board[j][i] == '.') continue;
                if(set.find(board[j][i]) != set.end())
                    return false;
                set.insert(board[j][i]);
            }
        }
        
        //for sub-block.
        for(int i=0;i<9;i++) {
            unordered_set<char> set;
            for(int j=0;j<9;j++) {
                if(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] == '.')
                    continue;
                if(set.find(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]) != set.end())
                    return false;
                set.insert(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]);
            }
        }
        return true;
    }
};