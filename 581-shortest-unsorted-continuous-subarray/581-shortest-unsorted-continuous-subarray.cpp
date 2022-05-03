class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int end = -1, start = 0;
        int mx = nums[0], mn = nums[n - 1];
        for(int i=1;i<n;i++) {
            if(nums[i] < mx)
                end = i;
            else
                mx = nums[i];
            
            if(nums[n - i - 1] > mn)
                start = n - i - 1;
            else
                mn = nums[n - i - 1];
        }
        
        return end - start + 1;
    }
};