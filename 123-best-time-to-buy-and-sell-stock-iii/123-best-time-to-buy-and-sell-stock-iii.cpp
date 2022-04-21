class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n);
        
        //calculate profit by right movement.
        int left = prices[0];
        dp1[0] = 0;
        
        for(int i=1;i<n;i++) {
            left = min(left, prices[i]);
            dp1[i] = max(dp1[i - 1], prices[i] - left);
        }
        
        //calculate profit by left movement.
        int right = prices[n - 1];
        vector<int> dp2(n, 0);
        dp2[n-1] = 0;
        
        for(int i=n-2;i>=0;i--) {
            right = max(right, prices[i]);
            dp2[i] = max(dp2[i + 1], right - prices[i]);
        }
        
        //adding both segment to get max profit.
        int profit = 0;
        for(int i=0;i<n;i++)
            profit = max(profit, dp1[i] + dp2[i]);
        
        return profit;
    }
};

/*
We have to do atmost two transiction it means
1.To maxmise profit the day we sold first stock and at same day we buy second stock.
2. [ a to i] and [i to b] two segment working on
3. In [ a to i] left part we try to find maximum profit from buying stock in past.
4. In [i to n] right part we try to sell stock maximum profit in future
5. Every point of i we find the maximu profit make when we move left or right
*/