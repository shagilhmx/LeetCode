class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i=0;i<nums.size();i++) umap[nums[i]]++;
        
        int ans = 0;
        for(auto it=umap.begin();it!=umap.end();it++) {
            if(it -> second == 1) ans = it -> first;
        }
        return ans;
    }
};