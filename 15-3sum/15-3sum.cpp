class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-1;i++) {
            if(i == 0 ||  (i > 0 && nums[i] != nums[i - 1])) {
                int start = i + 1, end = n - 1, res = 0 - nums[i];
                while(start < end) {
                    if(nums[start] + nums[end] == res) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        ans.push_back(temp);
                        
                        while(start < end && temp[1] == nums[start])
                            start++;
                        while(start < end && temp[2] == nums[end])
                            end--;
                    }
                    else if(nums[start] + nums[end] < res)
                        start++;
                    else
                        end--;
                }
            }
        }
        
        return ans;
    }
};