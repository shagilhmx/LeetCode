class Solution {
public:
    double myPow(double x, int n) {
        long nn;
        double ans = 1.0;
        
        nn = abs(n);
        
        while(nn > 0) {
            if(nn % 2) {
                ans *= x;
                nn -= 1;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        
        if(n < 0)
            ans = (double) 1.0 / (double) ans;
        
        return  ans;
    }
};