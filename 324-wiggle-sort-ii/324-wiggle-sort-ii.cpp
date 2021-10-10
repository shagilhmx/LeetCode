class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector res(nums);
        int j = nums.size()-1;
        for(int i=1;i<nums.size();i+=2){
            swap(res[i], nums[j--]);
        }
        
        for(int i=0;i<nums.size();i+=2){
            swap(res[i], nums[j--]);
        }
        nums = res;
    }
};