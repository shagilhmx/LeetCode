class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0, currSum = 0;
        int n = cardPoints.size();
        if(k >= n) {
            for(int el : cardPoints)
                res += el;
            return res;
        }
        
        //sweep right;
        int tailIndex;
        for(int i=0;i<k;i++) {
            currSum += cardPoints[i];
            res = max(res, currSum);
            tailIndex = i;
        }
        
        //sweep from left while reducing the right tail.
        int count = 0;
        for(int i=n-1;i>=0;i--) {
            currSum += cardPoints[i] - cardPoints[tailIndex--];
            res = max(res, currSum);
            
            count++;
            if(count >= k)
                break;
        }
        
        return res;
    }
};