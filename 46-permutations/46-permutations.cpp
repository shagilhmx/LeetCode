class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        int freq[nums.size()];
        
        for(int i=0;i<nums.size();i++) freq[i] = 0;
        
        helper(nums, freq, ds);
        
        return ans;
    }
    
    void helper(vector<int>& nums, int *freq, vector<int>& ds) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                helper(nums, freq, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
};