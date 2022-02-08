class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 2) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size()-2] != nums[nums.size()-1]) return nums[nums.size()-1];
        
        int jump = 1;
        while(jump <= nums.size()-1) {
            if(nums[jump-1] == nums[jump]) jump += 3;
            else return nums[jump-1];
        }
        return nums[0];
    }
};