class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        bool dp[n+1][n+1];
        
        unordered_set<string> dict;
        
        for(string word : wordDict) dict.insert(word);
        
        for(int i=1;i<=n;++i) { //window size
            int start = 1;
            int end = i;
            
            while(end <= n) { //sliding window
                string sub = s.substr(start - 1, i);
                if(dict.find(sub) != dict.end()) dp[start][end] = true;
                else { //partition into smaller and check
                    bool flag = false;
                    for(int p=start;p<end;++p) {
                        if(dp[start][p] && dp[p + 1][end]) {
                            flag = true;
                            break;
                        }
                    }
                    dp[start][end] = flag;
                }
                start++;
                end++;
            }
        }
        return dp[1][n];
    }
};