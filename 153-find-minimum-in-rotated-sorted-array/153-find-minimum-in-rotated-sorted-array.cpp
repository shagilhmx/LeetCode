class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        while(start <= end) {
            int mid = start + (end  - start)/ 2.0;
            
            if(nums[mid] >= nums[start] && nums[mid] <= nums[end]) //increseing order.
                return nums[start];
            else if(nums[mid] >= nums[end] && nums[mid] <= nums[start]) //decreasing order.
                return nums[end];
            else if(nums[mid] > nums[start])
                start = mid;
            else if(nums[mid] < nums[end])
                end = mid;
        }
        
        return INT_MAX;
    }
};

/*
[1, 2, 3, 4, 5] -> increasing.
[5, 4, 3, 2, 1] -> decreasing.
*/