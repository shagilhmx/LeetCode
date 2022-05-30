class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        helper(0, {}, s);
        
        return ans;
    }
    
    void helper(int index, vector<string> ds, string& s) {
        if(index == s.length()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index;i<s.length();i++) {
            if(isPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));
                helper(i + 1, ds, s);
                ds.pop_back();
            }
        }
        return;
    }
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
};