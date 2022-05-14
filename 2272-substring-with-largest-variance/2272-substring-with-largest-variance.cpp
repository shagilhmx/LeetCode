class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        
        vector<int> currFreq(26, 0);
        for(int i=0;i<n;i++) {
            int c = (int)s[i] - 'a';
            currFreq[c]++;
            freq[i] = currFreq;
        }
        
        int maxVariance = 0;
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                if(i == j || freq[n - 1][i] == 0 || freq[n - 1][j] == 0)
                    continue;
                
                int maxFreq = 0, minFreq = 0;
                for(int k=0;k<n;k++) {
                    int ch = (int)(s[k] - 'a');
                    
                    if(ch == i) minFreq++;
                    if(ch == j) maxFreq++;
                    
                    if(minFreq > 0)
                        maxVariance = max(maxVariance, maxFreq - minFreq);
                    
                    if(maxFreq < minFreq && freq[n - 1][i] - freq[k][i] != 0)
                        maxFreq = minFreq = 0;
                }
            }
        }
        
        return maxVariance;
    }
};