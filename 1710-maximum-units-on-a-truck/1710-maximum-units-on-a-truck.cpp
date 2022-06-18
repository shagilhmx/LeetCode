class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        
        int maxSize = 0;
        for(auto each : boxTypes) {
            if(truckSize < each[0]) {
                maxSize += truckSize * each[1];
                truckSize = 0;
                break;
            }
            
            maxSize += each[1] * each[0];
            truckSize-=each[0];
        }
        
        return maxSize;
    }
    
    static bool comparator(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};