class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long ans = (long(k) * long(k + 1))/2;
        
        //for adding unique number in the array.
        unordered_set<int> st(nums.begin(), nums.end());
        nums.clear();
        for(auto &elem : st) nums.push_back(elem);
        
        sort(nums.begin(), nums.end());
        
        int sz = nums.size();
        
        for(int i=0;i<sz;i++) {
            //if you have added the number which is already in nums then remove that and add next candidate k + 1.
            if(nums[i] <= k) {
                ans -= nums[i];
                ans += k + 1;
                k++;
            }
            else break;
        }
        return ans;
    }
};