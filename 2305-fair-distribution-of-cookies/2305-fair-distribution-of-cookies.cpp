class Solution {
    int ans = INT_MAX;
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> dist(k);
        
        solve(0, k, cookies, dist);
        return ans;
    }

    void solve(int index, int k, vector<int>& cookies, vector<int>& dist) {
        if(index == cookies.size()) {
            ans = min(ans, *max_element(dist.begin(), dist.end()));
            return;
        }
        
        for(int i=0;i<k;i++) {
            dist[i] += cookies[index];
            solve(index + 1, k, cookies, dist);
            dist[i] -= cookies[index];
            if(dist[i] == 0)
                break;
        }
    }
};