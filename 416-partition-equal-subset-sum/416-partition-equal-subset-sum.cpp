class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int el : nums) sum += el;
        
        if(sum % 2 != 0) return false;
        
        sum = sum / 2;
        int n = nums.size();
        
        int dp[n + 1][sum + 1];
        
        //initilization
        for(int i=0;i<=sum;i++) 
            dp[0][i] = false;
        for(int i=0;i<=n;i++)
            dp[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++) {
                if(nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};