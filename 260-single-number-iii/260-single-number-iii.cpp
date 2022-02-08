class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> umap;
        for(auto elem : nums) umap[elem]++;
        
        for(auto it : umap) {
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};