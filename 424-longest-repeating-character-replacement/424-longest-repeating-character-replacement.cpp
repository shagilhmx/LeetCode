class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mpp;
        int left = 0;
        int maxLen = 0;
        int ans = 0;
        
        for(int right=0;right<s.length();right++) {
            mpp[s[right]]++;
            
            maxLen = max(maxLen, mpp[s[right]]);
            
            if((right - left + 1) - maxLen > k) {
                mpp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};