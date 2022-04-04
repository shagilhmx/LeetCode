// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int maxIndex, maxVal = 0, cnt;
            for(int i=0;i<N;i++) {
                int low = 0, high = M - 1, oneIndex = -1;
                while(low <= high) {
                    int mid = (low + high) / 2;
                    if(Mat[i][mid] < 1)
                        low = mid + 1;
                    else {
                        high = mid - 1;
                        oneIndex = mid;
                    }
                }
                if(oneIndex == -1)
                    cnt = 0;
                else cnt = M - oneIndex;
                
                if(cnt > maxVal) {
                    maxVal = cnt;
                    maxIndex = i;
                }
            }
            
            return maxIndex;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends