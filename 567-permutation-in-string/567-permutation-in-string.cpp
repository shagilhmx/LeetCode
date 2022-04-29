class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);
        vector<int> hashNext(26, 0);
        int windowSize = s1.length();
        int len = s2.length();
        
        if(windowSize > len)
            return false;
        
        int left = 0, right = 0;
        while(right < windowSize) {
            hash[s1[right] - 'a']++;
            hashNext[s2[right++] - 'a']++;
        }
        right--;
        //sliding window.
        while(right < len) {
            if(hash == hashNext)
                return true;
            
            right++;
            if(right != len)
                hashNext[s2[right] - 'a']++;
            hashNext[s2[left] - 'a']--;
            left++;
        }
        return false;
    }
};