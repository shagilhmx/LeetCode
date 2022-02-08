class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for(auto elem : nums) {
            ones = (ones ^ elem) & (~twos);
            twos = (twos ^ elem) & (~ones);
        }
        return ones;
    }
};