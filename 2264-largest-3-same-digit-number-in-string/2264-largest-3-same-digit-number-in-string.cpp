class Solution {
public:
    string largestGoodInteger(string nums) {
        int n = nums.length();
        string ans = "";
        
        for(int i=0;i<n-1;i++) {
            string temp= "";
            for(int j=i;j<i+3;j++) {
                if(nums[i] != nums[j])
                    break;
                temp += nums[j];
            }
            
            if(temp > ans && temp.length() == 3)
                ans = temp;
        }
        
        return ans;
     }
};