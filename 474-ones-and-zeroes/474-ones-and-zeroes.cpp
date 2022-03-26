class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        return helper(size-1, strs, n, m, dp);
    }
    
    int helper(int r, vector<string>& strs, int n, int m, vector<vector<vector<int>>>& dp) {
        int zeros = 0, ones = 0;
        
        for(auto el : strs[r]) { //counting one's and zero's in each string.
            if(el == '0') zeros++;
            else ones++;
        }
        
        if(r == 0) {
            if(m - zeros >= 0 && n - ones >= 0) return 1;
            return 0;
        }
        
        if(dp[r][m][n] != -1) return dp[r][m][n];
        
        int notPick = helper(r - 1, strs, n, m, dp);
        int pick = INT_MIN;
        
        if(m - zeros >= 0 && n - ones >= 0)
            pick = helper(r-1, strs, n - ones, m - zeros, dp) + 1;
        
        return dp[r][m][n] = max(pick, notPick);
    }
};