class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //using dp
        int n = nums.size();
        vector<int> dp(n, -1);
        
        int res = 1;
        for(int i=0;i<n;i++)
            res = max(res, helper(nums, dp, i));
        
        return res;
    }
    
    int helper(vector<int>& nums, vector<int>& dp, int index) {
        if(index == nums.size()-1) {
            dp[index] = 1;
            return 1;
        }
        
        if(dp[index] != -1) return dp[index];
        
        int res = 1;
        
        for(int i=index+1;i<nums.size();i++) 
            if(nums[i] > nums[index])
                res = max(res, 1 + helper(nums, dp, i));
        
        dp[index] = res;
        return res;
    }
};