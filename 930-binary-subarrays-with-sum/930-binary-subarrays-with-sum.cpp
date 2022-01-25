class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, count = 0;
        unordered_map<int, int>umap;
        
        umap[0] = 1;
        
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(umap.find(sum - goal) != umap.end()) count += umap[sum - goal];
            umap[sum]++;
        }
        return count;
    }
};