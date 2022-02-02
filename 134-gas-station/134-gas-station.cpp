class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGasLeft = 0;
        int gasLeft = 0;
        int start = 0;
        
        for(int i=0;i<n;i++) {
            totalGasLeft += gas[i] - cost[i];
            gasLeft += gas[i] - cost[i];
            if(gasLeft < 0) {
                gasLeft = 0;
                start = i + 1;
            }
        }
        return totalGasLeft < 0 ? -1 : start;
    }
};