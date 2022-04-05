class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        
        for(int el : candies)
            sum += el;
        
        long long left = 0, right = sum / k;
        
        right++;
        long long ans = 0;
        while(left < right) {
            long long mid = (left + right) / 2;
            
            if(mid == 0)
                return 0;
            
            long long cnt = 0;
            for(int& el : candies)
                cnt += el/mid;
            
            if(cnt >= k) {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else
                right = mid;
        }
        
        return ans;
    }
};