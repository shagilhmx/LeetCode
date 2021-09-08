class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> res;
        for(auto &x : nums)
            umap[x]++;
        
        for(auto it=umap.begin();it!=umap.end();it++)
            if(it -> second > 1) res.push_back(it->first);
        
        return res;
            
    }
};