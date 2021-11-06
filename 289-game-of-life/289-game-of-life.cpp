class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> newVector = board;
        
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                int ones = 0;
                if((j-1) > -1 && (board[i][j-1])) ++ones;
                if((j+1) < c && (board[i][j+1])) ++ones;
                if((i-1) > -1 && (board[i-1][j])) ++ones;
                if((i+1) < r && (board[i+1][j])) ++ones;
                if((i-1)>-1 && (j-1)>-1 && (board[i-1][j-1])) ++ones;
                if((i-1)>-1 && (j+1)<c && (board[i-1][j+1])) ++ones;
                if((i+1)<r && (j-1)>-1 && (board[i+1][j-1])) ++ones;
                if((i+1)<r && (j+1)<c && (board[i+1][j+1])) ++ones;   
                if(board[i][j] == 1){
                    if(ones<2) newVector[i][j] = 0;
                    else if(ones == 2 || ones == 3) newVector[i][j] = 1;
                    else if(ones > 3) newVector[i][j] = 0;
                }
                else{
                    if(ones == 3) newVector[i][j] = 1;
                    else newVector[i][j] = 0;
                }
            }
        }
        board = newVector;
    }
};