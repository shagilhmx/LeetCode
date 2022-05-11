class Solution {
public:
    int countVowelStrings(int n) {
        int vowelsSize = 5;
        string vowels = "aeiou";
        
        vector<vector<int>> dp(vowelsSize, vector<int>(n + 1, -1));
        //return helper(vowels, 0, n);
        //return solve(vowels, 0, n, dp);
        return dynamicPrograming(vowels, n , dp);
    }
    
    int helper(string vowels, int index, int end) {
        if(end == 0) //a string of length n is formed.
            return 1;
        
        if(index == vowels.size()) //if vowels are exausted.
            return 0;
        
        int pick = helper(vowels, index, end - 1);
        int notPick = helper(vowels, index + 1, end);
        
        return pick + notPick;
    }
    
    int solve(string vowels, int index, int end, vector<vector<int>>& dp) {
        if(end == 0)
            return 1;
        
        if(index == vowels.size())
            return 0;
        
        if(dp[index][end] != -1)
            return dp[index][end];
        
        int pick = helper(vowels, index, end - 1);
        int notPick = helper(vowels, index + 1, end);
        
        return dp[index][end] = pick + notPick;
    }
    
    int dynamicPrograming(string vowels, int n, vector<vector<int>>& dp) {
        for(int i=0;i<5;i++)
            dp[i][0] = 1; //base case.
        
        for(int i=4;i>=0;i--) {
            for(int j=1;j<=n;j++) {
                int pick = 0, notPick = 0;
                
                pick = dp[i][j - 1];
                if(i < 4)
                    notPick = dp[i + 1][j];
                
                dp[i][j] = pick + notPick; 
            }
        }
        
        return dp[0][n]; // return all strings possible starting from 0 index and of n length
    }
};