class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ds;
        
        helper(0, ds, nums, INT_MIN);
            
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void helper(int index, vector<int>& ds, vector<int>& nums, int prev) {
        if(index >= nums.size()) {
            return;
        }
        
        for(int i=index;i<nums.size();i++) {
            if(nums[i] >= prev) {
                ds.push_back(nums[i]);
                if(ds.size() >= 2) ans.insert(ds);
                helper(i + 1, ds, nums, nums[i]);
                ds.pop_back();
            }
        }
    }
};