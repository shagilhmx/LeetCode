class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> countOne(n + 1, 0), countZero(n + 1, 0);
        
        //move from left and after first encounter of '1' make everything as '1'.
        //move from right and after first encounter of '0' make everything as '0'.
        
        for(int i=0;i<n;i++) {
            countOne[i + 1] = countOne[i] + s[i] - '0';
            countZero[n - i - 1] = countZero[n - i] + '1' - s[n - i - 1];
        }
        
        int res = n;
        for(int i=0;i<=n;i++)
            res = min(res, countOne[i] + countZero[i]);
        
        return res;
    }
};