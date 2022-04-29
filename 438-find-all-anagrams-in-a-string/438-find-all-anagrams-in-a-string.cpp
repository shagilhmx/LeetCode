class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //sliding window
        vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int windowSize = p.length();
        int len = s.length();
        
        if(len < windowSize)
            return ans;
        
        int left = 0, right = 0;
        //for 1st window.
        while(right < windowSize) {
            phash[p[right] - 'a']++;
            hash[s[right++] - 'a']++;
        }
        right -= 1;
        //sliding window for all the string.
        while(right<len) {
            if(phash == hash)
                ans.push_back(left);
            right++;
            if(right != len)
                hash[s[right] - 'a']++;
            hash[s[left] - 'a']--;
            left++;
        }
        return ans;
    }
};