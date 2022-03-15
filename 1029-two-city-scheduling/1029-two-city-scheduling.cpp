struct scheduling {
    int costA;
    int costB;
    int profit;
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        struct scheduling arr[n];
        
        for(int i=0;i<n;i++) arr[i].costA = costs[i][0], arr[i].costB = costs[i][1], arr[i].profit = costs[i][1] - costs[i][0];
        
        sort(arr, arr + n, comparator);
        
        int a = n/2;
        
        int sum = 0;
        
        for(int i=0;i<a;i++) sum += arr[i].costA;
        for(int i=a;i<n;i++) sum += arr[i].costB;
        
        return sum;
    }
    
    static bool comparator(scheduling a, scheduling b) {
        return a.profit > b.profit;
    }
};