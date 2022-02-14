class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> s;
        vector<int> ans;
        
        reverse(nums2.begin(), nums2.end());
            
        for(int elem : nums2) {
            while(!s.empty() && s.top() <= elem) s.pop();
            
            if(s.empty()) mp[elem] = -1;
            else mp[elem] = s.top();
            s.push(elem);
        }
        
        for(int i=0;i<nums1.size();i++) ans.push_back(mp[nums1[i]]);
        
        return ans;
    }
};