class Solution {
    public int jump(int[] nums) {
        int n = nums.length - 1;
        int res = 0;
        int left = 0, right = 0; //for window size.
        
        while(right < n) {
            int maxJump = 0;
            for(int i=left;i<=right;i++)
                maxJump = Math.max(maxJump, i + nums[i]);
            
            left = right + 1;
            right = maxJump;
            res++;
        }
        return res;
    }
}