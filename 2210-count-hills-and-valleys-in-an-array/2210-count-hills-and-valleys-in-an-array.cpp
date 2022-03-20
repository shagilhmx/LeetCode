class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return 0;
        
        int ans = 0;
        bool h_expection = false, v_expection = false;
        for(int i=1;i<n;i++) {
            if(nums[i] > nums[i - 1]) {
                h_expection = true;
                if(v_expection) {
                    v_expection = false;
                    ans++;
                }
            }
            
            if(nums[i] < nums[i - 1]) {
                v_expection = true;
                if(h_expection) {
                    h_expection = false;
                    ans++;
                }
            }
        }
        return ans;
    }
};