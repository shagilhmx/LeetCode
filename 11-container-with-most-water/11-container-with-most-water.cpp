class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxLen = 0;
        
        while(left <= right) {
            maxLen = max(maxLen, min(height[right], height[left]) * (right - left));
            if(height[left] < height[right])
                left++;
            else 
                right--;
        }
        
        return maxLen;
    }
};