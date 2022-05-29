class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mpp;
        
        for(auto el : nums)
            mpp.insert(el);
        
        int maxLen = 0;
        for(int i=0;i<nums.size();i++) {
            if(!mpp.count(nums[i] - 1)) {
                int len = 0;
                while(mpp.count(nums[i]++))
                    len++;
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};