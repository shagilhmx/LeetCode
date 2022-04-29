class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int[] left = new int[k + 1];
        int[] right = new int[k +1];
        
        left[0] = 0; right[0] = 0;
        
        for(int i=0;i<k;i++) {
            left[i + 1] = left[i] + cardPoints[i];
            right[i + 1] = right[i] + cardPoints[n - 1 - i];
        }
        
        int res = 0;
        for(int i=0;i<=k;i++)
            res = Math.max(res, left[i] + right[k - i]);
        
        return res;
    }
}