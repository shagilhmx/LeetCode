class Solution {
public:
    vector<string> ans;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        helper("", 0, s, wordDict);
        
        return ans;
    }
    
    void helper(string sub_ans, int index, string s, vector<string>& wordDict) {
        if(index >= s.length()) {
            ans.push_back(sub_ans.substr(0, sub_ans.length()-1));
            return;
        }
        
        for(int i=index;i<s.length();i++) {
            string sub = s.substr(index, i + 1 - index);
            if(found(sub, wordDict)) {
                helper(sub_ans + sub + " ", i + 1, s, wordDict);
            }
        }
    }
    
    bool found(string word, vector<string>& wordDict) {
        for(string key : wordDict) if(key == word) return true;
        return false;
    }
};