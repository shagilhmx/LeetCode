class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int curr = 0, next = 1, toNext = 1;
        
        for(int i=n-1;i>=0;i--) {
            string oneDig = string(1, s[i]), twoDig = s.substr(i, 2);
            
            int val = 0;
            if(oneDig == "0")
                curr = 0;
            else {
                if(stoi(oneDig) < 10)
                    val += next;
                if(stoi(twoDig) >= 10 && stoi(twoDig) < 27)
                    val += toNext;
                
                curr = val;
            }
            toNext = next;
            next = curr;
        }
        
        return curr;
    }
};