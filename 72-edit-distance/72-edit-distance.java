class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        
        int[][] dp = new int[n + 1][m + 1];
        for(int[] row : dp)
            Arrays.fill(row, -1);
        
        return lcs(word1, word2, n, m, dp);
    }
    
    int lcs(String word1, String word2, int n, int m, int[][] dp) {
        if(n == 0 || m == 0) {
            return n == 0 ? m : n;
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(word1.charAt(n - 1) == word2.charAt(m - 1))
            return dp[n][m] = lcs(word1, word2, n - 1, m - 1, dp);
        
        else {
            int insert = 1 + lcs(word1, word2, n, m - 1, dp);
            int replace = 1 + lcs(word1, word2, n - 1, m, dp);
            int remove = 1 + lcs(word1, word2, n - 1, m - 1, dp);
            dp[n][m] = Math.min(replace, Math.min(insert, remove));
        }
        return dp[n][m];
    }
}