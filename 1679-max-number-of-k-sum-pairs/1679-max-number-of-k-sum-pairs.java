class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1, count = 0;
        
        while(left < right && nums[left] < k) {
            if(nums[left] + nums[right] > k)
                right--;
            else if(nums[left] + nums[right] < k)
                left++;
            else {
                count++;
                left++;
                right--;
            }
        }
        
        return count;
    }
}