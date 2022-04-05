class Solution {
public:
    long long numberOfWays(string s) {
        return helper("101", s) + helper("010", s);
    }
    
    long long helper(string required, string s) {
        if(s.size() == 0)
            return 0;
        
        long long a = 0, b = 0, c = 0;
        for(char ch : s) {
            if(ch == required[0])
                a += 1;
            if(ch == required[1])
                b += a;
            if(ch == required[2])
                c += b;
        }
        
        return c;
    }
};