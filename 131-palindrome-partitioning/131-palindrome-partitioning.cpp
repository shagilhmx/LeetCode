class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        
        helper(0, s, ds);
        
        return ans;
    }
    
    void helper(int index, string s, vector<string>& ds) {
        if(index >= s.length()) {
            ans.push_back(ds);
            return;
        }
        
        //main recursive function.
        for(int i=index;i<s.length();i++) {
            if(isPalindrome(s, index, i)) {
                string res = s.substr(index, i - index + 1);
                ds.push_back(res);
                helper(i+1, s, ds);
                ds.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};