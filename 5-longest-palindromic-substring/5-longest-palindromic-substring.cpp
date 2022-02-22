class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
                if(i==j) dp[i][j]=1;
                if(j==i+1 && s[i]==s[j]) dp[i][j]=1;
            }
        }
        for(int i=2;i<n;i++){
            int r=0,col=i;
            while(col<n){
                if(s[r]==s[col] && dp[r+1][col-1]==1) dp[r][col]=1;
                r++;
                col++;
            }
        }
        int start=0,end=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==1){
                    if(j-i>end-start){
                        start=i;
                        end=j;
                    }
                }
            }
        }
        
        return s.substr(start,end-start+1);
    }
};