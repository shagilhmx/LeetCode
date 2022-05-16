class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<int> mpp;
        
        int left = 0, right = 0, maxLen = 0;
        while(right < n) {
            if(!mpp.count(s[right])) {
                mpp.insert(s[right]);
                maxLen = max(maxLen, (int)mpp.size());
                right++;
            }
            else {
                mpp.erase(s[left]);
                left++;
            }
        }
        
        return maxLen;
    }
};