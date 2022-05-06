class Solution {
    map<int, set<string>> wordOfSameLength;
    map<string, int> dp;
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        
        for(auto el : words)
            wordOfSameLength[el.length()].insert(el);
        
        int maxi = 0;
        for(auto word : words) {
            if(maxi > word.length())
                return maxi;
            
            maxi = max(maxi, dfs(word, 1));
        }
        
        return maxi;
    }
    
    static bool comparator(string& a, string& b) {
        return a.length() > b.length();
    }
    
    int dfs(string& word, int len) {
        if(!wordOfSameLength.count(word.length() - 1)) {
            dp[word] = len;
            return len;
        }
        
        if(dp.count(word))
            return dp[word];
        
        int localMax = len;
        for(int i=0;i<word.length();i++) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            if(wordOfSameLength[predecessor.length()].count(predecessor))
                localMax = max(localMax, dfs(predecessor, len + 1));
        }
        
        dp[word] = localMax;
        return localMax;
    }
};