class Solution {
public:
    int dp[50001];
    bool canReach(vector<int>& arr, int start) {
        memset(dp, -1, sizeof(dp));
        set<int> vis;
        return solve(start, arr, vis);
    }
    
    int solve(int start, vector<int>& arr, set<int>& vis) {
        if(start < 0 || start >= arr.size())
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        if(vis.count(start))
            return 0;
        
        vis.insert(start);
        
        if(arr[start] == 0)
            return 1;
        
        return dp[start] = solve(start + arr[start], arr, vis) || solve(start - arr[start], arr, vis);
    }
};