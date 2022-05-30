class Solution {
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        
        if(board.size() == 0 && board[0].size() == 0)
            return; //if size is 0 return.
        
        //check if its the border elem and mark it as '.' as we can mark it back to 'O' if its not connected.
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'O' && isBorder(i, j, board.size(), board[0].size())) {
                    board[i][j] = '.';
                    q.push({i, j});
                }
            }
        }

        //bfs to mark the middle and border elem connected to 'X'.
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for(auto d : dir) {
                int dx = d.first + curr.first;
                int dy = d.second + curr.second;
                
                if(dx >= 0 && dx < board.size() && dy >= 0 && dy < board[0].size() && board[dx][dy] == 'O') {
                    board[dx][dy] = '.';
                    q.push({dx, dy});
                }
            }
        }
        
        //marking the non connected end elems back to 'O' and all the others to 'X'.
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '.')
                    board[i][j] = 'O';
            }
        }
    }
    
    bool isBorder(int i, int j, int n, int m) {
        //to check if its the border elem.
        if(i == n - 1 || i == 0 || j == m - 1 || j == 0)
            return true;
        return false;
    }
};