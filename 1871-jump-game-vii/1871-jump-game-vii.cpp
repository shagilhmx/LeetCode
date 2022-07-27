class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length(), l=0;
        vector<bool> dp(n);
        dp[0] = true;
        
        for(int i=0;i<n;i++) {
            if(!dp[i])
                continue;
            for(int j=max(i+minJump, l);j<=min(i+maxJump, n - 1);j++)
               if(s[j] == '0')
                   dp[j] = true;
            l = min(i+maxJump, n - 1) + 1;
        }
        
        return dp[n - 1];
    }
};