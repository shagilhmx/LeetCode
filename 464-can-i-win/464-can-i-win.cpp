class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        long long totalScore = (maxChoosableInteger*(maxChoosableInteger+1))/2;
        
        if(totalScore < desiredTotal) return false;
        if(desiredTotal == 0) return true;
        
        vector<int> dp(1 << (maxChoosableInteger + 1), -1);
        
        return helper(0, 0, dp, maxChoosableInteger, desiredTotal);
    }
    
    bool helper(int sum, int index, vector<int>& dp, int maxChoosableInteger, int desiredTotal) {
        if(dp[index] != -1) return dp[index];
        
        /*if(setBits == 0 && (1..maxChoosableInteger) + sum >= desiredTotal || check for fun(i + sum, index | (1 << i))) return dp[index]*/
        
        for(int i=1;i<=maxChoosableInteger;i++)
            if((index & (1 << i)) == 0 && (i + sum >= desiredTotal || !helper(i + sum, index | (1 << i), dp, maxChoosableInteger, desiredTotal))) 
                return dp[index] = 1;
        return dp[index] = 0;
    }
};