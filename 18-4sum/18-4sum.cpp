class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if(nums.empty())
            return ans;
        
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++){
                int start = j + 1, end = nums.size() - 1;
                while(start < end) {
                    long long target2 = (long long)nums[i] + (long long)nums[j] + (long long)nums[start] + (long long)nums[end];
                    if(target == target2) {
                        vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[start];
                        temp[3] = nums[end];
                        ans.push_back(temp);
                        
                        while(start < end && nums[start] == temp[2])
                            ++start;
                        while(start < end && nums[end] == temp[3])
                            --end;
                    }
                    else if(target < target2)
                        end--;
                    else
                        start++;
                }
                while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        
        return ans;
    }
};