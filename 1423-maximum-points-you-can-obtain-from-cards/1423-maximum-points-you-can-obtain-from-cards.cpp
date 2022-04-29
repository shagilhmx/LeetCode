class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> left(k + 1), right(k +1);
        
        left[0] = 0, right[0] = 0;
        
        for(int i=0;i<k;i++) {
            left[i + 1] = left[i] + cardPoints[i];
            right[i + 1] = right[i] + cardPoints[n - 1 - i];
        }
        
        int res = 0;
        for(int i=0;i<=k;i++)
            res = max(res, left[i] + right[k - i]);
        
        return res;
    }
};