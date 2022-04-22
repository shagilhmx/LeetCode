class Solution {
    int dp[1001][101][3];
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, k, false);
    }
    
    int helper(vector<int>& prices, int index, int k, bool onGoing) {
        if(index >= prices.size() || k == 0)
            return 0;
        
        if(dp[index][k][onGoing] != -1)
            return dp[index][k][onGoing];
        
        int profit = 0;
        if(onGoing) {
            int sell = helper(prices, index + 1, k - 1, false) + prices[index];
            int notSell = helper(prices, index + 1, k, onGoing);
            profit = max(sell, notSell);
        }
        else {
            int buy = helper(prices, index + 1, k, true) - prices[index];
            int notBuy = helper(prices, index + 1, k, false);
            profit = max(buy, notBuy);
        }
        
        return dp[index][k][onGoing] = profit;
    }
};