class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        
        while(right < n) {
            if(nums[right]%2 == 0)
                swap(nums[left++], nums[right]);
            right++;
        }
        return nums;
    }
};