class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, -1));
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1) return 0;
        return helper(0, 0, obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid, dp);
    }
    
    int helper(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(i == n || j == m) return 0; //base condition for out-of-range.
        
        if(obstacleGrid[i][j] == 1) return 0;
        
        if(i == n - 1 && j == m - 1) dp[i][j] = 1; //base condition for reach destination.
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = helper(i + 1, j, n, m, obstacleGrid, dp) + helper(i, j + 1, n, m, obstacleGrid, dp);
    }
};