class Solution {
public:
    struct jobs {
        int start;
        int end;
        int profit;
    };
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n =startTime.size();
        struct jobs job[n];
        int dp[n];
        
        for(int i=0;i<n;i++) job[i].start = startTime[i], job[i].end = endTime[i], job[i].profit = profit[i];
        
        sort(job, job + n, comparator);
        
        dp[n-1] = job[n-1].profit;
        
        for(int i=n-2;i>=0;i--) {
            int index = binarySearch(job, n, job[i].end, i);
            int profit = index == -1 ? 0 : dp[index];
            dp[i] = max(dp[i+1], profit + job[i].profit);
        }
        return dp[0];
    }
    
    static bool comparator(jobs a, jobs b) {
        return a.start < b.start;
    }
    
    int binarySearch(struct jobs *arr, int n, int val, int start) {
        int end = n-1;
        int ans = -1;
        
        while(start <= end) {
            int mid = (start + (end - start) / 2);
            if(arr[mid].start >= val) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};