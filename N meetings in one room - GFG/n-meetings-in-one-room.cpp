// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    struct meeting {
        int startTime;
        int endTime;
        int pos;
    };
    
    public:
    int maxMeetings(int start[], int end[], int n)
    {  
        struct meeting meet[n];
        for(int i=0;i<n;i++) meet[i].startTime = start[i], meet[i].endTime = end[i], meet[i].pos = i + 1;
        
        sort(meet, meet+n, comparator);
        
        vector<int> ans;
        
        int limit = meet[0].endTime;
        ans.push_back(meet[0].pos);
        
        int count = 1;
        
        for(int i=1;i<n;i++) {
            if(meet[i].startTime >limit) {
                limit = meet[i].endTime;
                ans.push_back(meet[i].pos);
                count++;
            }
        }
        return count;
    }
    
    static bool comparator(struct meeting a, struct meeting b) {
        if(a.endTime < b.endTime) return true;
        else if(a.endTime > b.endTime) return false;
        else if(a.pos < b.pos) return true;
        else return false;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends