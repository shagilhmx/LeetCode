class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        
        int toReach = n - 1;
        for(int i=toReach;i>=0;i--)
            if(i + nums[i] >= toReach)
                toReach = i;
        
        return toReach == 0 ? true : false;
    }
}