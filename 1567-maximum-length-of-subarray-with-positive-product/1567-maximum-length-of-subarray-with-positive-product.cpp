#define ll long long int
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        ll n = nums.size(), i, ans = 0;
        ll pos = nums[0] > 0 ? 1 : 0, neg = nums[0] < 0 ? 1 : 0;
        ans = pos;
        
        for(int i=1;i<n;i++) {
            if(nums[i] > 0) {
                pos = pos + 1;
                neg = neg > 0 ? 1 + neg : 0; 
            }
            else if(nums[i] < 0) {
                int temp = pos;
                pos = neg > 0 ? 1 + neg : 0;
                neg = temp + 1;
            }
            else
                pos = neg = 0;
            
            ans = max(ans, pos);
        }
        
        return ans;
    }
};