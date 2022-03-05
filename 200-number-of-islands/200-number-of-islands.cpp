class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int noOfIslands = 0;
        
        if(row == 0) return 0;
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, row, col);
                    noOfIslands++;
                }
            }
        }
        return noOfIslands;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) { //m->rows, n->cols
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return; //base condition
        
        grid[i][j] = '2'; //we have taken a cell marked as 2, as visited.
        
        dfs(grid, i + 1, j, m, n); //down
        dfs(grid, i, j + 1, m, n); //right
        dfs(grid, i - 1, j, m, n); //up
        dfs(grid, i, j - 1, m, n); //left
    }
};