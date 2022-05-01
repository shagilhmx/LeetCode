class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long n = nums.size();
        vector<long> left(n, 0), right(n, 0);
        left[0] = nums[0], right[n - 1] = nums[n - 1];
        
        for(long i=1;i<n;i++)
            left[i] = left[i - 1] + nums[i];
            
        for(long i=n-2;i>=0;i--)
            right[i] = right[i + 1] + nums[i];
        
        long minDiff = INT_MAX, index = 0;
        for(int i=0;i<n;i++) {
            int diff = (i == n - 1) ? abs((left[i] / (i + 1)) - 0 ) : abs((left[i] / (i + 1)) - (right[i + 1] / (n - 1 - i)));
            if(diff < minDiff) {
                index = i;
                minDiff = diff;
            }
        }
        return index;
    }
};