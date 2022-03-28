class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, index = -1;;
        vector<int> ans;
        
        //for end
        while(start <= end) {
            int mid = (end + start) / 2;
            
            if(nums[mid] == target) {
                index = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        ans.push_back(index);
        
        //for start.
        start = 0, end = nums.size() - 1, index = -1;
        while(start <= end) {
            int mid = (end + start) / 2;
            
            if(nums[mid] == target) {
                index = mid;
                start = mid + 1;
            }
            else if(target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        ans.push_back(index);
        
        return ans;
    }
};