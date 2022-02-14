class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hmap;
        vector<int> ans(nums1.size(), 0);
        
        for(int i=0;i<nums2.size();i++) hmap[nums2[i]] = i;
        
        for(int i=0;i<nums1.size();i++) {
            int index = hmap[nums1[i]];
            for(int j=index;j<nums2.size();j++) {
                if(nums2[j] > nums1[i]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
            if(ans[i] == 0) ans[i] = -1;
        }
        return ans;
    }
};