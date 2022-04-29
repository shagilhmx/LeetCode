class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //maxSubArraySum - minSubArraySum = maxSubarraySum.
        int maxSum = maxSubArraySum(nums);
        int minSum = minSubArraySum(nums);
        
        int sum = 0;
        for(int el : nums)
            sum += el;
        
        //sum == minSum, return 
        if(sum == minSum)
            return maxSum;
        
        return max(maxSum, sum - minSum);
    }
    
    int maxSubArraySum(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++) {
            sum += nums[i];
            
            if(sum < 0)
                sum = 0;
            
            maxSum = max(maxSum, sum);
        }
        
        int minEl = *max_element(nums.begin(), nums.end());
        if(minEl < 0)
            maxSum = minEl;
        return maxSum;
    }
    
    int minSubArraySum(vector<int>& nums) {
        int minSum = INT_MAX, sum = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++) {
            sum += nums[i];
            
            if(sum > 0)
                sum = 0;
            
            minSum = min(minSum, sum);
        }
        
        int maxEl = *min_element(nums.begin(), nums.end());
        if(maxEl > 0)
            minSum = maxEl;
        return minSum;
    }
};