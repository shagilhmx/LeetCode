class Solution {
    long long mod = 1e9 + 7;
    long long dp[100001];
public:
    int countTexts(string pressedKeys) {
        memset(dp, -1, sizeof(dp));
        return solve(pressedKeys, 0);
    }
    
    long long solve(string& s, int index) {
        if(index == s.size())
            return 1;
        
        if(dp[index] != -1)
            return dp[index];
        
        long long ans = 0;
        
        if(s[index] == '9' || s[index] == '7') {
            char temp = s[index];
            for(int i=index;i<index+4;i++) {
                if(s[i] == temp)
                    ans = (ans + solve(s, i + 1)) % mod;
                else
                    break;
            }
        }
        else {
            char temp = s[index];
            for(int i=index;i<index+3;i++) {
                if(s[i] == temp)
                    ans = (ans + solve(s, i + 1)) % mod;
                else
                    break;
            }
        }
        
        return dp[index] = ans % mod;
    }
};