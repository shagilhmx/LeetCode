class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int sum = 0;
        int rem = 0;
        int count = 0;
        umap[sum] = 1;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            rem = sum % k;
            if(rem < 0) rem += k;
            if(umap.find(rem) != umap.end()) {
                count += umap[rem];
                umap[rem] ++;
            }
            else umap[rem] = 1;
        }
        return count;
    }
};