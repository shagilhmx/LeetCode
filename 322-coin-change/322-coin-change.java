class Solution {
    public int coinChange(int[] coins, int amount) {
        //tabulation dp
        int n = coins.length;
        int[][] dp = new int[n + 1][amount + 1];
        
        for(int i=0;i<=n;i++)
            Arrays.fill(dp[i], -1);
        
        int minCoins = tabulation(coins, amount, coins.length, dp);
        return minCoins == Integer.MAX_VALUE - 1 ? -1 : minCoins;
    }
    
    int tabulation(int[] coins, int amount, int n, int[][] dp) {
        //initilizing the first row with inf.
        for(int i=1;i<=amount;i++)
            dp[0][i] = Integer.MAX_VALUE - 1;
        
        //initilizing the first col with 0.
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        
        for(int i=1;i<dp.length;i++) {
            for(int j=1;j<dp[0].length;j++) {
                if(coins[i - 1] <= j)
                    dp[i][j] = Math.min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
}