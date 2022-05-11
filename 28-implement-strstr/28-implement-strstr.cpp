class Solution {
public:
    int strStr(string haystack, string needle) {
        //using kmp algorithm.
        int n = haystack.length(), m = needle.length();
        
        if(needle.length() == 0)
            return 0;
        
        vector<int> lps(m, 0);
        int prev = 0, curr = 1;
        
        //fill lps array.
        while(curr < m) {
            if(needle[curr] == needle[prev])
                lps[curr++] = prev++ + 1;
            else {
                if(prev == 0)
                    lps[curr++] = 0;
                else
                    prev = lps[prev - 1];
            }
        }
        
        int i = 0, j = 0;
        while(i < n) {
            if(haystack[i] == needle[j])
                i++, j++;
            
            else {
                if(j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
            
            if(j == m)
                return i - m;
        }
        
        return -1;
    }
};