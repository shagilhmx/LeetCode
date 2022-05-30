class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        
        for(int i=0;i<s.length();i++) {
            for(int j=0;j<=i;j++) {
                if(i - j <= 2)
                    dp[i][j] = s[i] == s[j] ? true : false;
                else {
                    if(dp[i - 1][j + 1])
                        dp[i][j] = s[i] == s[j] ? true : false;
                }
            }
        }
        
        helper(0, {}, s, dp);
        
        return ans;
    }
    
    void helper(int index, vector<string> ds, string& s, vector<vector<int>>& dp) {
        if(index == s.length()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index;i<s.length();i++) {
            if(dp[i][index]) {
                ds.push_back(s.substr(index, i - index + 1));
                helper(i + 1, ds, s, dp);
                ds.pop_back();
            }
        }
        return;
    }
};