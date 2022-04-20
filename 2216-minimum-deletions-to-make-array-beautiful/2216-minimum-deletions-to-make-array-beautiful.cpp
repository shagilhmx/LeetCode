class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return true;
        
        stack<int> st;
        
        for(int num : nums)
            if(st.empty() || st.size() % 2 == 0 || st.top() != num) 
                st.push(num);
        
        int deleted = nums.size() - st.size();
        
        return st.size() % 2 ? deleted + 1 : deleted;
    }
};