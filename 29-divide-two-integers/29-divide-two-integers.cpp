class Solution {
public:
    int divide(int dividend, int divisor) {
        if((dividend == INT_MIN || dividend == INT_MAX) && (divisor == -1 || divisor == 1)) return (dividend >= 0 == divisor >= 0) ? INT_MAX : INT_MIN;
        
        int res = 0;
        long long new_dividend = abs(dividend), new_divisor = abs(divisor);
        
        while((new_dividend - new_divisor) >= 0) {
            int x = 0;
            
            while(new_dividend - (new_divisor << 1 << x) >= 0) x++;
            res += 1 << x;
            
            new_dividend -= new_divisor << x;
        } 
        return (dividend >= 0 == divisor >= 0) ? res : -res;
    }
};