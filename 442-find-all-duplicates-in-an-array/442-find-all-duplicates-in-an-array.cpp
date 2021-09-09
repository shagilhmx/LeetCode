class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto &x : nums){
            if(nums[abs(x)-1] > 0) nums[abs(x)-1] = -nums[abs(x)-1];
            else res.push_back(abs(x));
        }
        return res;
    }
};