class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> q;
        q.push(-1);
        
        int maxLen = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(')
                q.push(i);
            else {
                q.pop();
                if(!q.empty()) {
                    maxLen = max(maxLen, i - q.top());
                }
                else
                    q.push(i);
            }
        }
        return maxLen;
    }
};