class Solution {
    public void sortColors(int[] nums) {
        int left=0, mid=0, right=nums.length-1;
        
        while(mid <= right) {
            switch(nums[mid]) {
                case 0:
                    swap(nums, left++, mid++);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums, mid, right--);
                    break;
            }
        }
    }
    
    void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}