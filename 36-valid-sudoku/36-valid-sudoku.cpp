class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int i=0;i<n;i++) {
            unordered_set<char> mpp;
            for(int j=0;j<m;j++) {
                if(board[i][j] == '.')
                    continue;
                else if(mpp.count(board[i][j]))
                    return false;
                mpp.insert(board[i][j]);
            }
        }
        
        for(int i=0;i<n;i++) {
            unordered_set<char> mpp;
            for(int j=0;j<m;j++) {
                if(board[j][i] == '.')
                    continue;
                else if(mpp.count(board[j][i]))
                    return false;
                mpp.insert(board[j][i]);
            }
        }
        
        for(int i=0;i<n;i++) {
            unordered_set<char> mpp;
            for(int j=0;j<m;j++) {
                if(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] == '.')
                    continue;
                else if(mpp.count(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]))
                    return false;
                mpp.insert(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]);
            }
        }
        
        return true;
    }
};