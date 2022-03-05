class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> hmap(s.length());
        return helper("", 0, s, wordDict, hmap);
    }
    
    bool helper(string sub_ans, int index, string s, vector<string>& wordDict, unordered_map<int, bool>& hmap) {
        if(index >= s.length()) return true;
        if(hmap.count(index)) return hmap[index];
        
        
        for(int i=index;i<s.length();i++)
            if(found(s.substr(index, i + 1 - index), wordDict) && helper(s.substr(index, i + 1 - index), i + 1, s, wordDict, hmap)) return hmap[index] = true;
        return hmap[index]= false;
    }
    
    bool found(string word, vector<string>& wordDict) {
        for(string key : wordDict) if(key == word) return true;
        return false;
    }
};