class Solution {
public:
    int countVowelStrings(int n) {
        int vowelsSize = 5;
        string vowels = "aeiou";
        
        vector<vector<int>> dp(vowelsSize + 1, vector<int>(n + 1, -1));
        //return helper(vowels, 0, n);
        return solve(vowels, 0, n, dp);
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
};