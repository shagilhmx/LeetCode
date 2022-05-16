class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, end = 0, ans = INT_MIN;
        int dp[n][n];
        for(int gap=0;gap<n;gap++) {
            for(int i=0,j=gap;j<n;j++,i++) {
                if(gap == 0)
                    dp[i][j] = 1;
                else if(gap == 1) {
                    if(s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else {
                    if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                
                if(j - i > ans && dp[i][j] == 1) {
                    ans = j - i;
                    start = i;
                    end = j - i + 1;
                }
            }
        }
        
        return s.substr(start,end);
    }
};