class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        unsigned int x = 0;
        for(auto i : nums) x ^= i;
        x = (x ^ (x-1)) & x;
        for(auto elem : nums) {
            if(x & elem) ans[0] ^= elem;
            else ans[1] ^= elem;
        }
        return ans;
    }
};