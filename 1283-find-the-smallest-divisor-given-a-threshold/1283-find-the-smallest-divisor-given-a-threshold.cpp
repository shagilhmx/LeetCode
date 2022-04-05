class Solution {
    bool isPossible(vector<int>& nums, int threshold, int mid) {
        long long divisor = 0;
        
        for(int el : nums)
            divisor += ceil(1.0 * el / mid);
        
        if(divisor <= threshold)
            return true;
        return false;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long left = 1, right = *max_element(nums.begin(), nums.end());
        
        long long ans = 0;
        while(left <= right) {
            long long mid = (left + right) / 2;
            
            if(isPossible(nums, threshold, mid)) {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
};