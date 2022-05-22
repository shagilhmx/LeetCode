class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int j = 0;
        while(s[j] == ' ')
            j++;
        
        if(s[j] == '-' || s[j] == '+') {
            if(s[j] == '-')
                sign = -1;
            j++;
        }
        
        for(int i=j;i<s.length();i++) {
            if(isdigit(s[i])) {
                ans = ans * 10 + (s[i] - '0');
                if(ans * sign >= INT_MAX)
                    return INT_MAX;
                if(ans * sign <= INT_MIN)
                    return INT_MIN;
            }
            else
                break;
        }
        
        return sign * ans;
    }
};