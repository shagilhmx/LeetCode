class Solution {
    struct timeContraints {
        int arrivals;
        int leaving;
        int id;
    };
    
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        timeContraints arr[n];
        
        for(int i=0;i<n;i++) {
            arr[i].arrivals = times[i][0]; 
            arr[i].leaving = times[i][1];
            arr[i].id = i;
        }
        
        sort(arr, arr + n, comparator);
        
        set<int> unoccupied;
        int ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
            unoccupied.insert(i);
        
        for(int i=0;i<n;i++) {
            while(!pq.empty() && pq.top().first <= arr[i].arrivals) {
                unoccupied.insert(pq.top().second);
                pq.pop();
            }
            
            int pos = *(unoccupied.begin());
            if(targetFriend == arr[i].id) {
                ans = pos;
                break;
            }
            
            unoccupied.erase(unoccupied.begin());
            pq.push({arr[i].leaving, pos});
        }
        
        return ans;
    }
    
    static bool comparator(timeContraints& a, timeContraints& b) {
        if(a.arrivals == b.arrivals)
            return a.id < b.id;
        return a.arrivals < b.arrivals;
    }
};