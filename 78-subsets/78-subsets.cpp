class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        
        sort(nums.begin(), nums.end());
        helper(0, nums, ds);
        
        return ans;
    }
    
    void helper(int index, vector<int>& nums, vector<int>& ds) {
        ans.push_back(ds);
        
        for(int i=index;i<nums.size();i++) {
            if(i != index && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i + 1, nums, ds);
            ds.pop_back();
        }
    }
};