class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> mpp;
        
        for(int i=0;i<nums.size();i++) {
            int count = 0;
            string temp = "";
            for(int j=i;j<nums.size();j++) {
                temp += (nums[j] + '0');
                if(nums[j] % p == 0)
                    count++;
                
                if(count <= k)
                    mpp.insert(temp);
                
                if(count > k)
                    break;
            }
        }
        return mpp.size();
    }
};