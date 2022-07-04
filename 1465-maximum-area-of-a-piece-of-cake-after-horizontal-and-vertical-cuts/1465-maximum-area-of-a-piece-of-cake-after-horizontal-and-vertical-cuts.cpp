class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long mod = 1e9 + 7, maxHoriDiff , maxVerDiff;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h), verticalCuts.push_back(w);
        
        maxHoriDiff = maxDiff(horizontalCuts);
        maxVerDiff = maxDiff(verticalCuts);
        
        return (maxHoriDiff * maxVerDiff) % mod;
    }
    
    int maxDiff(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
            ans = max((nums[i] - nums[i - 1]), ans);
        
        return ans;
    }
};