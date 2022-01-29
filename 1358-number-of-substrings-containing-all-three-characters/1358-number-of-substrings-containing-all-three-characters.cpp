class Solution {
public:
    int numberOfSubstrings(string s) {
        return sliding(s);
    }
    
    int sliding(string s) {
        unordered_map<int, int> umap;
        
        int i = 0, res = 0;
        
        for(int j=0;j<s.length();++j) {
            ++umap[s[j]];
            while(umap['a'] && umap['b'] && umap['c']) --umap[s[i++]];
            res += i;
        }
        return res;
    }
};