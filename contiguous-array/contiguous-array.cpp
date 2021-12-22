class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxLen = 0;
        unordered_map<int, int> umap;
        umap.insert({0,-1});
        for (int i=0;i<nums.size();i++){
            nums[i] == 1 ? sum++:sum--;
            if(umap.find(sum) != umap.end())
                maxLen = max(maxLen, i - umap[sum]);
            else umap[sum] = i;
        }
        return maxLen;
    }
};