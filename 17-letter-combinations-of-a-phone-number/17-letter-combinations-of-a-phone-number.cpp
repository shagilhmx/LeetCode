class Solution {
    map<char, string> mpp;
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        mpp['2'] = "abc", mpp['3'] = "def", mpp['4'] = "ghi", mpp['5'] = "jkl", mpp['6'] = "mno", mpp['7'] = "pqrs", mpp['8'] = "tuv", mpp['9'] = "wxyz";
        
        solve(digits, 0, "");
        
        return res;
    }
    
    void solve(string& digits, int index, string ds) {
        if(index == digits.length()) {
            res.push_back(ds);
            return;
        }
        
        string temp = mpp[digits[index]];
        for(int i=0;i<temp.length();i++)
            solve(digits, index + 1, ds + temp[i]);
    }
};