class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        sort(nums1.begin(), nums1.end());
        while(i < m+n && nums1[i] != 0) i++;
        cout<<i;
        int j = 0;
        while(i<n+m && j < n) {nums1[i] = nums2[j]; j++;i++;}
        sort(nums1.begin(), nums1.end());
    }
};