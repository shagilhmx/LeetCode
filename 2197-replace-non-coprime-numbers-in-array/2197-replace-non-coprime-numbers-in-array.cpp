class Solution {
private:
    bool isCoPrime(int x, int y) {
        return __gcd(x, y) == 1;
    }
    
    int lcm(int x, int y) {
        long long LCM = x;
        LCM *= y;
        LCM /= __gcd(x, y);
        return LCM;
    }
    
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        ans.push_back(nums[0]); //ans = {nums[0]}.
        
        for(int i=1;i<n;i++) {
            int curr = nums[i]; //curr = {nums[1]},..., ans = {nums[n-1]}.
            while(ans.size() && !isCoPrime(ans.back(), curr)) {
                int top = ans.back();
                ans.pop_back();
                curr = lcm(curr, top);
            } 
            ans.push_back(curr);
        }
        return ans;
    }
};