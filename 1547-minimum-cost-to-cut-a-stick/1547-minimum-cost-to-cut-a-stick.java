class Solution {
    int dp[101][101];
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        
        sort(cuts.begin(), cuts.end());
        
        return solve(0, n, cuts, 0, cuts.size() - 1, dp);
    }
    
    int solve(int start, int end, vector<int>& cuts, int st, int ed, int dp[101][101]) {
        if(st > ed) return 0;
        
        if(dp[st][ed] != -1)
            return dp[st][ed];
        
        int cost = INT_MAX;
        
        for(int i=st;i<=ed;i++) {
            int left = solve(start, cuts[i], cuts, st, i - 1, dp);
            int right = solve(cuts[i], end, cuts, i + 1, ed, dp);
            int curr_cost = (end - start) + left + right;
            cost = min(cost, curr_cost);
        }
        
        return dp[st][ed] = cost;
    }
};