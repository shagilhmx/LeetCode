class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums, {});
        
        return ans;
    }
    
    void solve(int index, vector<int>& nums, vector<int> ds) {
        ans.push_back(ds);
        
        for(int i=index;i<nums.size();i++) {
            ds.push_back(nums[i]);
            solve(i + 1, nums, ds);
            ds.pop_back();
        }
    }
};