class Solution {
public:
    vector<string> ans;
    set<string> hmap;
    vector<string> letterCasePermutation(string s) {
        
        helper(0, s);
        
        return ans;
    }
    
    void helper(int index, string s) {
        if(index >= s.length()) {
            ans.push_back(s);
            return;
        }
        
        char x = s[index];
        s[index] = isupper(s[index]) ? tolower(s[index]) : toupper(s[index]);
        helper(index + 1, s);
        if(isalpha(x)) {
            s[index] = x;
            helper(index + 1, s);
        }
    }
};