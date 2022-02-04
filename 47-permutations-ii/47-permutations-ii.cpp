class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> hmap;
        vector<int> ds;
        
        for(int i=0;i<nums.size();i++) hmap[nums[i]]++;
        
        helper(hmap, ds, nums.size());
        
        return ans;
    }
    
    void helper(unordered_map<int, int>& hmap, vector<int> ds, int size) {
        if(ds.size() == size) {
            ans.push_back(ds);
            return;
        }
        
        for(auto it=hmap.begin();it!=hmap.end();it++) {
            if(it->second > 0) {
                ds.push_back(it->first);
                hmap[it->first]--;
                helper(hmap, ds, size);
                hmap[it->first]++;
                ds.pop_back();
            }
        }
    }
};