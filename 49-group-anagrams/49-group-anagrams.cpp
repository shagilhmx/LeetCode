class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        int n = strs.size();
        
        for(int i=0;i<n;i++) {
            vector<int> mask(26, 0);
            for(int ch : strs[i])
                mask[ch - 'a']++;
            
            mpp[mask].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto el : mpp)
            ans.push_back(el.second);
        
        return ans;
    }
};