class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, -1);
        
        for(int i=0;i<n;i++) dp[i] = getMask(words[i]);
        
        int maxValue = 0;
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((dp[i] & dp[j]) == 0) 
                    maxValue = max(maxValue, (int)(words[i].length()*words[j].length()));
        
        return maxValue;
    }
    
    int getMask(string word) {
        int n = 0;
        
        for(char ch : word) n |= (1 << (ch - 'a'));
        
        return n;
    }
};