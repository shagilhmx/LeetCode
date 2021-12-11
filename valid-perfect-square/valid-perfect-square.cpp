class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        
        while(left <= right){
            long long int mid = left + floor((right - left)/2);
            
            if(mid * mid == num) return true;
            else if(mid * mid > num) right = mid-1;
            else left = mid + 1;
        }
        return false;
    }
};