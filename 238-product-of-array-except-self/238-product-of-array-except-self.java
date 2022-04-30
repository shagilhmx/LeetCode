class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        //storing the prefix
        int prefix = 1;
        for(int i=0;i<n;i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        
        //storing the postfix from end to start.
        int postfix = 1;
        for(int i=n-1;i>=0;i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        
        return ans;
    }
};