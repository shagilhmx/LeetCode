class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int leftIndex = 0, rightIndex = 0, n = nums.length;
        
        //get left bad index.
        for(int i=1;i<n;i++) {
            if(nums[i] < nums[i - 1]) {
                leftIndex = i - 1;
                break;
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            if(nums[i] > nums[i+1]) {
                rightIndex = i + 1;
                break;
            }
        }
        
        //find the smallest and largest numbers.
        int mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
        for(int i=leftIndex;i<=rightIndex;i++) {
            mn = Math.min(mn, nums[i]);
            mx = Math.max(mx, nums[i]);
        }
        
        if(leftIndex == rightIndex)
            return 0;
        
        int ans = rightIndex - leftIndex + 1;
        int left = leftIndex;
        while(left - 1 >= 0 && mn < nums[left - 1]) {
            ans++;
            left--;
        }
        
        int right = rightIndex;
        while(right + 1 < n && mx > nums[right + 1]) {
            ans++;
            right++;
        }
        
        return ans;
    }
}