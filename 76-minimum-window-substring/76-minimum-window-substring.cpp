class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_map;
        
        for(int i=0;i<t.length();i++) freq_map[t[i]]++;
        
        int i = 0, j = 0, matchCount = freq_map.size(), minLen = INT_MAX;
        string ans = "";
        
        while(j < s.length()) {
            
            if(freq_map.find(s[j]) != freq_map.end()) {
                freq_map[s[j]]--;
                if(freq_map[s[j]] == 0) matchCount--;
            }
            
            while(matchCount == 0) {
                if(minLen > j - i + 1) {
                    minLen = min(minLen, j - i + 1);
                    ans = s.substr(i, j -i + 1);
                }
                if(freq_map.find(s[i]) != freq_map.end()) {
                    freq_map[s[i]]++;
                    if(freq_map[s[i]] == 1) matchCount++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};