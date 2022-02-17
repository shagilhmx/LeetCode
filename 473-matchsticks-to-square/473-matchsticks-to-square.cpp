class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalSum = 0, n = matchsticks.size();
        for(int elem : matchsticks) totalSum += elem;
        
        //if(not possible to create a square, i.e not divisible by 4 or no of matchsticks are less than 4), return false.
        if(totalSum % 4 != 0 || n < 4) return false;
        
        int target = totalSum/4;
        
        vector<int> dp((1 << n), -1);//create a dp, vector of size 2^n;
        dp[0] = 0;
        
        for(int mask=0;mask<(1 << n);mask++) {
            if(dp[mask] == -1) continue; //invalid case
            
            for(int j=0;j<n;j++) {
                //if(setbit == 0)
                if(!(mask & (1 << j)) && dp[mask] + matchsticks[j] <= target)
                    dp[mask | (1 << j)] = (dp[mask] + matchsticks[j]) % target;
            }
        }
        return dp[(1 << n) -1] == 0 ? true : false;
    }
};