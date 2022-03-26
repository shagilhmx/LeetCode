class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue = nums[0], minValue = nums[0], res = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            int temp = maxValue;
            maxValue = max({nums[i], nums[i] * maxValue, nums[i] * minValue});
            minValue = min({nums[i], nums[i] * temp, nums[i] * minValue});
            res = max(res, maxValue);
        }
        return res;
    }
};