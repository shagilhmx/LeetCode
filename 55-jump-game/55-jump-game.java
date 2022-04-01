class Solution {
    int dp[10001];
public:
    bool canJump(vector<int>& nums) {
        //using memoisation.
        memset(dp, -1, sizeof(dp));
        return helper(0, nums, nums.size()-1);
    }
    
    bool helper(int index, vector<int>& nums, int n) {
        if(index > n)
            return false;
        if(dp[index] != -1)
            return dp[index];
        if(index == n)
            return dp[index] = true;
        
        for(int i=nums[index];i>=1;i--) {
            if(helper(index + i, nums, n))
                return dp[index] = true;
        }
        return dp[index] = false;
    }
};