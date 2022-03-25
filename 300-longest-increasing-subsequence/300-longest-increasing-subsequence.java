class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        
        int res = 1;
        for(int i=0;i<n;i++)
            res = Math.max(res, helper(nums, dp, i));
        
        return res;
    }
    
    int helper(int[] nums, int[] dp, int index) {
        if(index == nums.length-1) {
            dp[index] = 1;
            return 1;
        }
        
        if(dp[index] != -1) return dp[index];
        
        int res = 1;
        
        for(int i=index+1;i<nums.length;i++) 
            if(nums[i] > nums[index])
                res = Math.max(res, 1 + helper(nums, dp, i));
        
        dp[index] = res;
        return res;
    }
}