class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));
        int minCoins = helper(coins.size(), coins, amount, dp);
        
        return minCoins == INT_MAX - 1 ? -1 : minCoins;
    }
    
    int helper(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(index == 0 || amount == 0) 
            return (amount == 0) ? 0 : INT_MAX - 1;
        
        if(dp[amount][index] != -1)
            return dp[amount][index];
        
        if(coins[index - 1] > amount) 
            return dp[amount][index] = helper(index - 1, coins, amount, dp);
        else 
            return dp[amount][index] = min(1 + helper(index, coins, amount - coins[index - 1], dp), helper(index - 1, coins, amount, dp));
    }
};