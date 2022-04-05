class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1, right = 1e9;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            int cnt = 0;
            for(int el : piles)
                cnt += ceil(1.0 * el / mid);
            
            if(cnt > h)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        
        return left;
    }
};