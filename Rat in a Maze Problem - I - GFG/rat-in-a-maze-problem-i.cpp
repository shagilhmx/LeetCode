// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        helper(m, n, 0, 0, "", ans, visited);
        
        return ans;
    }
    
    void helper(vector<vector<int>>& m, int n, int x, int y, string sub_ans, vector<string> &ans, vector<vector<bool>>& visited) {
        if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || m[x][y] == 0) return;
        
        if(x == n-1 && y == n-1) {
            ans.push_back(sub_ans);
            return;
        }
        
        visited[x][y] = true;
        
        helper(m, n, x + 1, y, sub_ans + "D", ans, visited);
        helper(m, n, x, y - 1, sub_ans + "L", ans, visited);
        helper(m, n, x, y + 1, sub_ans + "R", ans, visited);
        helper(m, n, x - 1, y, sub_ans + "U", ans, visited);
        
        visited[x][y] = false;
        return;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends