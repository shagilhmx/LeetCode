class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size(), res = 0;
        
        for(int i=0;i<n;i++) {
            int mx = nums[i], mn = nums[i];
            for(int j=i+1;j<n;j++) {
                mx = max(nums[j], mx);
                mn = min(nums[j], mn);
                res += (mx - mn);
            }
        }
        return res;
    }
};