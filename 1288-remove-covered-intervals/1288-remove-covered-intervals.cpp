class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        
        int count = 1;
        int prev = 0;
        
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] >= intervals[prev][0] && intervals[i][1] <= intervals[prev][1]) continue;
            else {
                count++;
                prev = i;
            }
        }
        return count;
    }
    
    static bool comparator(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] >= b[1];
        else return a[0] < b[0];
    }
};