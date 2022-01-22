class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len, maxLen;
        len = maxLen = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 1) len++;
            else {
                maxLen = max(maxLen, len);
                len = 0;
            }
        }
        maxLen = max(len, maxLen);
        return maxLen;
    }
};