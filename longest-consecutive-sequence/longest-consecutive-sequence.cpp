class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> umap;
        for (int x : nums)
            if(umap.find(x) == umap.end())
                umap[x] = true;
        int max_count = 0;
        for(int i=0;i<nums.size();i++){
            if(umap.find(nums[i]-1) != umap.end())
                continue;
            else{
                int k = i, count = 0;
                while(umap.find(nums[k]++) != umap.end()) count++;
                if(max_count < count)
                    max_count = count;
            }
        }
        return max_count;
    }
};