class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mpp;
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        
        for(int right=0;right<s.length();right++) {
            mpp[s[right]]++;
            
            maxFreq = max(maxFreq, mpp[s[right]]);
            
            if((right - left + 1) - maxFreq > k) {
                mpp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};