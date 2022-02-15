class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ds(target, 0);
        int sum = 0;
        
        for(int elem : nums) sum += elem;
        
        if(sum%target != 0 || n < target) return false;
        
        sort(nums.begin(), nums.end());
        
        return helper(n-1, nums, sum/target, ds);
    }
    
    bool helper(int index, vector<int>& nums, int target, vector<int>& ds) {
        if(index == -1) return true;
        
        for(int i=0;i<ds.size();i++) {
            if((ds[i] + nums[index]) <= target) {
                ds[i] += nums[index];
                if(helper(index - 1, nums, target, ds)) return true;
                ds[i] -= nums[index];
            }
            
            if(ds[i] == 0) break;
        }
        return false;
    }
};