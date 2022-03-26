class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return helper(0, 0, 0, grid, dp);
    }
    
    int helper(int curr, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) { 
        if(i == grid.size()-1 && j == grid[0].size()-1) 
            return grid[i][j];
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int x = INT_MAX, y = INT_MAX; 
        if(i < grid.size()-1) x = grid[i][j] + helper(curr, i + 1, j, grid, dp);
        if(j < grid[0].size()-1) y = grid[i][j] + helper(curr, i, j + 1, grid, dp);
        return dp[i][j] = min(x, y);
    }
};