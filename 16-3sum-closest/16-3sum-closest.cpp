class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2;i++) {
            int pointerOne = i+1, pointerTwo = nums.size()-1;
            while(pointerOne < pointerTwo) {
                int sum = nums[i] + nums[pointerOne] + nums[pointerTwo];
                if(sum > target) pointerTwo--;
                else pointerOne++;
                
                if(abs(sum - target) < abs(res - target)) res = sum;
            }
        }
        return res;
    }
};