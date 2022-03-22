class Solution {
    int maxScore = 0;
    vector<int> ans;
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> bobArrows(12, 0);
        maxScore = INT_MIN;
        
        helper(bobArrows, 11, aliceArrows, numArrows, 0);
        
        int arrow_used = 0;
        for(int a : ans)
            arrow_used += a;
        
        if(arrow_used < numArrows) 
            ans[0] += (numArrows - arrow_used);
        
        return ans;
            
    }
    
    void helper(vector<int>& bobArrows, int index, vector<int>& aliceArrows, int numArrows, int score) {
        if(index == -1 || numArrows <= 0) {
            if(score >= maxScore) {
                maxScore = score;
                ans = bobArrows;
            }
            return;
        }
        
        helper(bobArrows, index - 1, aliceArrows, numArrows, score);
        
        if(numArrows > aliceArrows[index]) {
            bobArrows[index] =  aliceArrows[index] + 1;
            numArrows -= (aliceArrows[index] + 1);
            score += index;
            helper(bobArrows, index - 1, aliceArrows, numArrows, score);
            bobArrows[index] = 0;
        }
    }
};