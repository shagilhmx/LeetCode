class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        
        int currLeft = 1;
        for(int i=0;i<nums.size();i++){
            res[i] = currLeft;
            currLeft *= nums[i];
        }
        
        int currRight = 1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i] *= currRight;
            currRight *= nums[i];
        }
        
        return res;
    }
};