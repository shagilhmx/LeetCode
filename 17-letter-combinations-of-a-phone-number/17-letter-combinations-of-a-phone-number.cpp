class Solution {
    vector<string> ans;
    unordered_map<int, string> mpp;
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(n == 0)
            return ans;
        
        mpp[2] = "abc", mpp[3] = "def", mpp[4] = "ghi", mpp[5] = "jkl", mpp[6] = "mno", mpp[7] = "pqrs", mpp[8] = "tuv", mpp[9] = "wxyz";
        
        helper(0, n, digits, "");
        
        return ans;
    }
    
    void helper(int index, int n, string& digits, string sub_ans) {
        if(index == n) {
            ans.push_back(sub_ans);
            return;
        }
        
        string temp = mpp[digits[index] - '0'];
        for(int i=0;i<temp.length();i++)
            helper(index + 1, n, digits, sub_ans + temp[i]);
    }
};