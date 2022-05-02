class Solution {
public:
    int mySqrt(int x) {
        long long int low = 0, high = (long)1e9;
        while(low < high) {
            long mid = (low + high) >> 1;
            
            if(mid * mid == x)
                return mid;
            else if(mid * mid > x) 
                high = mid;
            else if(high - low == 1)
                return low;
            else
                low = mid;
        }
        return 1;
    }
};