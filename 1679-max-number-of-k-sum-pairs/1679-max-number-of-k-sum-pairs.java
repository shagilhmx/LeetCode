class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        int count = 0;
        for(int i=0;i<n;i++) {
            if(mpp[k - nums[i]] > 0) {
                count++;
                mpp[k - nums[i]]--;
            }
            else
                mpp[nums[i]]++;
        }
        
        return count;
    }
};