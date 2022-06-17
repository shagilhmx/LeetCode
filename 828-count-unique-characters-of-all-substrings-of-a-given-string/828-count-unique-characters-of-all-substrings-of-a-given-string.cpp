class Solution {
public:
    int uniqueLetterString(string s) {
        int res = 0, n = s.length(), mpp[26][2], mod = 1e9 + 7;
        memset(mpp, -1, sizeof(int) * 52);
        
        for(int i=0;i<n;i++) {
            int ch = s[i] - 'A';
            
            res = (res + (i - mpp[ch][1]) * (mpp[ch][1] - mpp[ch][0]) % mod) % mod;
            mpp[ch][0] = mpp[ch][1];
            mpp[ch][1] = i;
        }
        
        for(int c=0;c<26;c++)
            res = (res + (n - mpp[c][1]) * (mpp[c][1] - mpp[c][0]) % mod) % mod;
        
        return res;
    }
};