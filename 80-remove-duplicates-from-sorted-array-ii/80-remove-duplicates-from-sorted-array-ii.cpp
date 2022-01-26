class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        
        int slow = 2, fast = 2;
        
        while(fast < nums.size()) {
            if(nums[fast] != nums[slow-2]) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};