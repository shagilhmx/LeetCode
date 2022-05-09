class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i=0;i<n;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                long long count = 0;
                if(s[i - 1] == t[j - 1]) count += dp[i - 1][j - 1];
                count += dp[i - 1][j];
                dp[i][j] = count;
            }
        }
        return dp[n][m];
    }
};