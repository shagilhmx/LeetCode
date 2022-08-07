class Solution {
    int dp[10001];
public:
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        //return helper(0, nums, nums.size()-1);
        //return solve(0, nums, nums.size()-1);
        return dpSolution(nums);
    }
    
    int dpSolution(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);
        dp[n - 1] = 0;
    
        for(int i=n-2;i>=0;i--)
            for(int jumpLen=1;jumpLen<=nums[i];jumpLen++)
                dp[i] = min(dp[i], 1 + dp[min(n - 1, jumpLen + i)]);
    
        return dp[0];
    }
    
    int solve(int index, vector<int>& nums, int n) {
        if(index > n)
            return INT_MAX-1;
        if(index == n)
            return 0;
        
        int temp = INT_MAX - 1;
        for(int i=1;i<=nums[index] && i + index < nums.size();i++)
            temp = min(temp, solve(index + i, nums, n) + 1);
        
        return temp;
    }
    
    int helper(int index, vector<int>& nums, int n) {
        if(index > n)
            return INT_MAX-1;
        if(dp[index] != -1)
            return dp[index];
        if(index == n)
            return 0;
        
        int temp = INT_MAX-1;
        for(int i=1;i<=nums[index] && i + index < nums.size();i++) {
            temp = min(temp, helper(index + i, nums, n) + 1);
        }
        return dp[index] = temp;
    }
};