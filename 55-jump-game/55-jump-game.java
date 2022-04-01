class Solution {
    public boolean canJump(int[] nums) {
        //using greedy approch.
        /*we take a nums size value to reach to and start from end - 1 and check
        if we can reach to end from end - 1 by adding the elem, if yes then we
        make our goal to end - 1 - 1, which is end - 1 - i.
        */
        int toReach = nums.length - 1;
        
        for(int i=toReach-1;i>=0;i--) {
            if(nums[i] + i >= toReach)
                toReach = i;
        }
        return (toReach == 0) ? true : false; 
    }
}