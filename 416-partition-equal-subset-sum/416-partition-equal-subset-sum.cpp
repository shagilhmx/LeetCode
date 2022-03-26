class Solution {
    bool helper(vector<int>& nums , int i , int sum , vector<vector<int>>& dp){
        if(sum == 0)
            return true;
        
        if(i>=nums.size())
            return false;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        if(nums[i] <= sum)
            return dp[i][sum] = helper(nums,i+1,sum-nums[i],dp) || helper(nums,i+1,sum,dp);
        
        else
            return dp[i][sum] = helper(nums,i+1,sum,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums){
            sum += n;
        }
        if(sum%2 != 0)
            return false;
        int n = nums.size();
        sum = sum/2;
        vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
        return helper(nums,0,sum,dp);
    }
};