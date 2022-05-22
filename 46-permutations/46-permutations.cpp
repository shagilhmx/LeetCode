class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        solve(nums, 0, nums.size());
        
        return ans;
    }
    
    void solve(vector<int>& nums, int index, int n) {
        if(index == n) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<n;i++) {
            swap(nums[i], nums[index]);
            solve(nums, index + 1, n);
            swap(nums[i], nums[index]);
        }
        
        return;
    }
};