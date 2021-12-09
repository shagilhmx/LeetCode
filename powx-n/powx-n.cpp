class Solution {
public:
    double myPow(double x, int n) {
        double temp = 1.0;
        long nn = n;
        
        if(n < 0)
            nn = -1*nn;
        
        while(nn > 0){
            if(nn%2 != 0){
                temp *= x;
                nn = nn - 1;
            }
            else{
                x *= x;
                nn /= 2;
            }
        }
        if(n < 0) temp = (double)(1.0) / (double)(temp);
        return temp;
    }
};