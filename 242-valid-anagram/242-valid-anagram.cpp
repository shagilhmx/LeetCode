class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hmap;
        
        if(s.length() != t.length()) return false;
        
        for(auto ch : s) hmap[ch]++;
        
        for(auto ch : t) if(hmap.find(ch) != hmap.end()) hmap[ch]--;
        
        for(auto itr = hmap.begin(); itr != hmap.end(); itr++) if(itr -> second != 0) return false;
        return true;
    }
};