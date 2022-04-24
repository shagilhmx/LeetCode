class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
    
        helper(0, n, nums);
        
        return ans;
    }
    
    void helper(int index, int n, vector<int>& nums) {
        if(index >= n) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<n;i++) {
            swap(nums[index], nums[i]);
            helper(index + 1, n, nums);
            swap(nums[index], nums[i]);
        }
    }
};