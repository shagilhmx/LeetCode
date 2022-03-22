class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long maxCount = 0, cnt1 = 0, cnt2 = 0;
        
        for(char &c : text) {
            if(c == pattern[1]) {
                maxCount += cnt1;
                cnt2++;
            }
            if(c == pattern[0]) cnt1++;
        }
        return maxCount + max(cnt1, cnt2);
    }
};