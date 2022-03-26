class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int r = strs.length;
        int[][] dp = new int[m+1][n+1];
        
        //count zero and one for 1st index.
        int zero = 0, one = 0;
        for(int i=0;i<strs[0].length();i++) {
            if(strs[0].charAt(i) == '0') zero++;
            else one++;
        }
        
        //base case.
        for(int i=zero;i<=m;i++)
            for(int j=one;j<=n;j++)
                dp[i][j] = 1;
        
        for(int i=1;i<r;i++) {
            zero = one = 0; //counting number of zeros and ones.
            for(int j=0;j<strs[i].length();j++) {
                if(strs[i].charAt(j) == '0') zero++;
                else one++;
            }
            
            for(int j=m;j>=0;j--) {
                for(int k=n;k>=0;k--) {
                    int noPick = dp[j][k];
                    int pick = Integer.MIN_VALUE;
                    if(j - zero >= 0 && k - one >= 0)
                        pick = dp[j-zero][k-one] + 1;
                    dp[j][k] = Math.max(pick, noPick);
                }
            }
        }
        return dp[m][n];
    }
}