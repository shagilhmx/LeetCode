class Solution {
    int dp[10001];
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, n);
    }
    
    bool solve(int index, vector<int>& nums, int n) {
        if(index == n)
            return dp[index] = true;
        
        if(index > n)
            return false;
        
        if(dp[index] != -1)
            return dp[index];
        
        for(int i=nums[index];i>=1;i--)
            if(solve(index + i, nums, n))
                return dp[index] = true;
        
        return dp[index] = false;
    }
};