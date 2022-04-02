class Solution {
    int dp[10001];
public:
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(0, nums, nums.size()-1);
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