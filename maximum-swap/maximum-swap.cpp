class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        
        for(int i=0;i<nums.size();i++){
            int index = i;
            for(int j=nums.size()-1;j>i;j--){
                if(nums[index] < nums[j]) index = j;
            }
            if(index != i){
                swap(nums[index], nums[i]);
                break;
            }
        }
        return stoi(nums);
    }
};