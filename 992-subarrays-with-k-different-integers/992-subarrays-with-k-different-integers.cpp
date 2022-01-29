class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding(nums, k) - sliding(nums, k+1);
    }
    
    int sliding(vector<int>& A, int a) {
        unordered_map<int, int> umap;
        int res = 0, i = 0, cnt = 0;
        
        for(int j=0;j<A.size();++j) {
            if(!umap[A[j]]++) cnt++;
            while(cnt == a) {
                if(--umap[A[i]] == 0) cnt--;
                i++;
            }
            res += i;
        }
        return res;
    }
};