class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        map<vector<int>, vector<string>> hmap;
                
        for(auto word : strs) {
            
            vector<int> masking(26, 0);

            for(auto ch : word) {
                masking[ch - 'a']++;
            }
            
            hmap[masking].push_back(word);
        }
        
        for(auto data : hmap) ans.push_back(data.second);
        
        return ans;
    }
};