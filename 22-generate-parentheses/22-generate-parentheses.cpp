class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        solve(2*n ,0, 0, "");
        
        return ans;
    }
    
    void solve(int n, int open, int closed, string res) {
        if(open + closed >= n) {
            if(open == closed)
                ans.push_back(res);
            return;
        }
        
        if(closed < open)
            solve(n, open, closed + 1, res + ")");
        solve(n, open + 1, closed, res + "(");
    }
};