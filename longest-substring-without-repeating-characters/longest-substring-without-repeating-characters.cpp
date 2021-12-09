class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> umap(256, -1);
        
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while(right < n){
            if(umap[s[right]] != -1) left = max(umap[s[right]] + 1, left);
            umap[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};