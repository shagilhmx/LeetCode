class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2)
            return false;
        
        int ans = nums[0];
        map<int, int> mpp;
        
        for(int i=1;i<n;i++)
            mpp[nums[i]]++;
        
        for(int i=1;i<n;i++) {
            mpp[nums[i]]--;
            
            if(mpp[nums[i]] == 0)
                mpp.erase(nums[i]);
            
            if(nums[i] > ans) {
                auto el = mpp.upper_bound(ans);
                
                if(el != mpp.end() && el -> first < nums[i])
                    return true;
            }
            else {
                ans = min(ans, nums[i]);
            }
        }
        return false;
    }
};