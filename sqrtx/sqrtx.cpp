class Solution {
public:
    int mySqrt(int x) {
        long long int left = 1;
        long long int right = x;
        
        if(x < 2) return x;
        
        while(left < right){
            long long int mid = left + floor((right - left)/2);
        
            if(mid * mid == x) return mid;
            else if(mid * mid > x)
                right = mid;
            else if(mid * mid < x)
                left = mid + 1;
        }
        return left - 1;
    }
};