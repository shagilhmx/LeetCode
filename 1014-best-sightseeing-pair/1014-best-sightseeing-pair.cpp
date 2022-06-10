class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxVal = 0;
        int dp;
        dp = values[0];
        
        for(int i=1;i<n;i++) {
            dp = max(dp, values[i - 1] + i - 1);
            maxVal = max(maxVal, dp + values[i] - i);
        }
        
        return maxVal;
    }
};
/*
Suppose we have a = [8,1,5,2,6]
create a dp = [0, 0, 0, 0] where dp[i] represents the best possible answer if we consider all pairs forming with a[i] (like i = 3 then it will be (0, 3),(1, 3), (2, 3))

For d[0] it will be 0
For d[1] it will be a[0] + a[1] + 0 - 1
For d[2] it will be max((a[0] + a[2] + 0 - 2), (a[1] + a[2] + 1 - 2))
For d[3] it will be max((a[0] + a[3] + 0 - 3), (a[1] + a[3] + 1 - 3), (a[2] + a[3] + 2 - 3))
For d[4] it will be max(a[0] + a[4] + 0 - 4), (a[1] + a[4] + 1 - 4), (a[2] + a[4] + 2 - 4), (a[3] + a[4] + 3 - 4))
Rewriting above by taking about common term out of max() function

For d[0] it will be 0
For d[1] it will be a[0] + 0 + a[1] - 1
For d[2] it will be max((a[0] + 0), (a[1] + 1)) + a[2] - 2
For d[3] it will be max((a[0] + 0 ), (a[1] + 1), (a[2] + 2)) + a[3] - 3
For d[4] it will be max(a[0] + 0 ), (a[1] + 1), (a[2] + 2), (a[3] + 3 )) + a[4] - 4
For a minute lets ignore the part outside the max function and drop it for now, So make a new series and call it dp

For dp[0] it will be 0
For dp[1] it will be a[0] + 0
For dp[2] it will be max((a[0] + 0), (a[1] + 1))
For dp[3] it will be max((a[0] + 0 ), (a[1] + 1), (a[2] + 2))
For dp[4] it will be max(a[0] + 0 ), (a[1] + 1), (a[2] + 2), (a[3] + 3 ))
Here is the catch
dp[i] = max(dp[i-1], a[i-1] + i - 1)
You can Clearly see this pattern in above dp series

Combining this to d series we can get:

For d[0] it will be 0
For d[1] it will be dp[0]+ a[1] - 1
For d[2] it will be max(dp[1], (a[1] + 1)) + a[2] - 2
For d[3] it will be max(dp[2], (a[2] + 2)) + a[3] - 3
For d[4] it will be max(dp[3], (a[3] + 3 )) + a[4] - 4
Now our answer can simply the maximum of d that is max(d), but for improving space complexity i used maxVal to keep track of maximum value


*/