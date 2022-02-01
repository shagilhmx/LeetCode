class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comparator);
        
        int count = 0;
        
        for(int itr=0;itr<intervals.size()-1;itr++) {
            if(intervals[itr][1] <= intervals[itr+1][0]) continue;
            else {
                intervals[itr+1][1] = min(intervals[itr][1], intervals[itr+1][1]);
                count++;
            }
        }
        return count;
    }
    
    static bool comparator(vector<int> &a, vector<int> &b) {
        return (a[1] < b[1]);
    }
};