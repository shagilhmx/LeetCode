class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(2, vector<int>(n, -1));
        
        return helper(prices, 0, dp, false);
    }
    
    int helper(vector<int>& prices, int index, vector<vector<int>>& dp, bool onGoing) {
        if(index >= prices.size())
            return 0;
        
        if(dp[onGoing][index] != -1)
            return dp[onGoing][index];
        
        int profit = 0;
        if(onGoing) {
            int sell = helper(prices, index + 1, dp, false) + prices[index];
            int notSell = helper(prices, index + 1, dp, onGoing);
            profit = max(sell, notSell);
        }
        else {
            int buy = helper(prices, index + 1, dp, true) - prices[index];
            int notBuy = helper(prices, index + 1, dp, false);
            profit = max(buy, notBuy);
        }
        
        return dp[onGoing][index] = profit;
    }
};