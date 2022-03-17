class Solution {
public:
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
    
    int longestPalindromeSubseq(string s) {
        /*create a copy of the original string and reverse it,
        now do the longest common Subsequence on the two string,
        i.e get the longest common subsequence of the two strings.
        Thats the ans;
        */
        int n = s.length();
        string temp = s;
        reverse(temp.begin(), temp.end());
        
        return lcs(s, temp, n, n);
    }
    
    int lcs(string &s, string &t, int n, int m) {
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};