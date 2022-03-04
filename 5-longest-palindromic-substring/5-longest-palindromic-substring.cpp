class Solution {
public:
    string longestPalindrome(string s) {
        //using gap method
        int n = s.length();
        int start = 0, end = 0;
        
        bool dp[n][n];
        
        for(int gap=0;gap<n;gap++) {
            for(int i=0, j=gap;j<n;i++, j++) {
                if(gap == 0) dp[i][j] = true; //if only one character, i.e gap is zero.
                /* if two character, i.e 
                gap is 1, we check if both the character are same if yes return 2, otherwise                 1.*/
                else if(gap == 1) dp[i][j] = s[i] == s[j] ? true : false; 
                else {
                    if(s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = true; //2 + midPart(str).
                    }
                    else {
                        dp[i][j] = false; // max(c1m, mc2).
                    }
                }
                if(dp[i][j]) {
                    start = i;
                    end = j - i + 1;
                }
            }
        }
        return s.substr(start, end);
    }
};