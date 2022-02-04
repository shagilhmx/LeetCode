class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        helper(0, nums);
        
        sort(ans.begin(), ans.end());
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
    
    void helper(int index, vector<int>& nums) {
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++) {
            swap(nums[index], nums[i]);
            helper(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }
};