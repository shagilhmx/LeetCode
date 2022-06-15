class Solution {
    unordered_map<string, int> dp;
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        int res = 1;
        
        for(auto word : words) {
            dp[word] = 1;
            for(int i=0;i<word.length();i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if(dp.find(prev) != dp.end()) {
                    dp[word] = dp[prev] + 1;
                    res = max(res, dp[word]);
                }
            }
        }
        
        return res;
    }
    
    static bool comparator(string& a, string& b) {
        return a.length() < b.length();
    }
};