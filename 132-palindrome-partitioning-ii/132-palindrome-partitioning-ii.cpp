class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return helper(0, s.length() - 1, s, dp);
    }
    
    int helper(int start, int end, string& s, vector<vector<int>>& dp) {
        if(start == end || isPalindrome(s, start, end))
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int minCut = s.length() - 1;
        for(int i=start;i<=end;i++) {
            if(isPalindrome(s, start, i))
                minCut = min(minCut, 1 + helper(i + 1, end, s, dp));
        }
        
        return dp[start][end] = minCut;
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while(start < end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
};