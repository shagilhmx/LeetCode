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
        
        /*
        we have to get the max profit i.e costs[i][1] - cost[i][0] should be max,
        sort the array using this assumption and then sum up the first n/2 from costs[i][0]
        and the next remaning from cost[i][1].
        */
        
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