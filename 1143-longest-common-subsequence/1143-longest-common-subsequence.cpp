class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        
        int dp[1001][1001];
        for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) dp[i][j] = -1;
        
        return lcs(text1, text2, n, m, dp);
    }
    
    int lcs(string &text1, string &text2, int n, int m, int dp[][1001]) {
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(text1[n - 1] == text2[m - 1]) return dp[n][m] = 1 + lcs(text1, text2, n - 1, m - 1, dp);
        return dp[n][m] = max(lcs(text1, text2, n, m - 1, dp), lcs(text1, text2, n - 1, m, dp));
    }
};