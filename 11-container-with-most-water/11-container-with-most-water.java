class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        
        int amountOfWater = (right - left) * Math.min(height[right], height[left]);
        while(left <= right) {
            amountOfWater = Math.max(amountOfWater, (right - left) * Math.min(height[right], height[left]));
            if(height[left] < height[right])
                left++;
            else right--;
        }
        
        return amountOfWater;
    }
}