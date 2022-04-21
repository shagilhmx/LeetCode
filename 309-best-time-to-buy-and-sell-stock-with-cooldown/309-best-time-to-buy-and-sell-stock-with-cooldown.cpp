class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(n , -1));
        
        return helper(0, prices, false, dp);
    }
    
    int helper(int index, vector<int>& prices, bool onGoing, vector<vector<int>>& dp) {
        if(index >= prices.size())
            return 0;
        
        if(dp[onGoing][index] != -1)
            return dp[onGoing][index];
        
        int profit = 0;
        //we have two choices, either buy or not and either sell or not.
        if(onGoing) {
            int sell = helper(index + 2, prices, false, dp) + prices[index];
            int notSell = helper(index + 1, prices, onGoing, dp);
            profit = max(sell, notSell);
        }
        else {
            int buy = helper(index + 1, prices, true, dp) - prices[index];
            int notBuy = helper(index + 1, prices, false, dp);
            profit = max(buy, notBuy);
        }
        
        return dp[onGoing][index] = profit;
    }
};
/*
Let's make an recursive solution first..
so... for each transaction we have two option...
1: We can sell the stock
If we sell the stock then we can't buy the stock just next day cause of cooldown
2: or buy
We can buy stock if and only if there is no onGoing transaction..
So let's have a look of recursive solution
*/