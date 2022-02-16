class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return {};
        vector<string> ans;
        unordered_map<string, int> mp;
        
        int i = 0;
        
        while(i + 10 <= s.length()) {
            string subSeq = s.substr(i, i++ + 10 - i + 1);
            mp[subSeq]++;
            if(mp[subSeq] == 2) ans.push_back(subSeq);
        }
        
        return ans;
    }
};