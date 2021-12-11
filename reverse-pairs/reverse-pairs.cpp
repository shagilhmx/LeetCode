class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
    
    int merge_sort(vector<int> &nums, int start, int end){
        if(start >= end) return 0;
        int mid = (start + end)/2;
        
        int inv_count = merge_sort(nums, start, mid);
        inv_count += merge_sort(nums, mid+1, end);
        inv_count += merge(nums, start, mid, end);
        return inv_count;
    }
    
    int merge(vector<int> &nums, int p, int q, int r){
        int cnt = 0;
        int j = q+1;
        for(int i=p;i<=q;i++){
            while(j <= r && nums[i] > 2LL*nums[j])
                j++;
            cnt += (j - (q + 1));
        }
        
        vector<int> temp;
        int left = p, right = q + 1;
        while(left <= q && right <= r){
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        
        while(left <= q) temp.push_back(nums[left++]);
        while(right <= r) temp.push_back(nums[right++]);
        
        for(int i=p;i<=r;i++) nums[i] = temp[i-p];
        
        return cnt;
    }
};