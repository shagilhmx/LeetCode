class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = (int)sqrt(c);
        
        while(left <= right){
            long long total = left * left + right * right;
            if(total == c) return true;
            else if(total < c) left ++;
            else right --;
        }
        return false;
    }
};