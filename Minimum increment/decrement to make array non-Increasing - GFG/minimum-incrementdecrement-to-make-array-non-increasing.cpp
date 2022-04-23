// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends


class Solution{
public:
    int minOperations(int *a,int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int steps = 0;
        
        for(int i=0;i<n;i++) {
            if(!pq.empty() && pq.top() < a[i]) {
                steps += (a[i] - pq.top());
                pq.push(a[i]);
                pq.pop();
            }
            pq.push(a[i]);
        }
        
        return steps;
    }
};
/*
You have to make the current element a[i] lesser to all the previous elements in 0 -> (i-1)....
so maintain a min heap and add elements in it until you find a bigger element than the min till now.....when it is encountered, you make it lesser or equal to min and increase number of operations

for the input {3, 1, 5, 1}

1. i = 0, queue is empty initially ....so a[0] added in PQ -> [3]
2. i = 1, a[1] < pq.top ....so a[1] is added in PQ -> [3, 1]
3. i = 2, a[2] > pq.top ... so we make a[2] = pq.top() by decreasing a[2] (5) by 4 to make it 1 (pq.top). PQ -> [3, 5] ... operations = 4
4. i = 3 a[3] < pq.top.... so a[3] is added in PQ -> [3, 5, 1]

return operations ... ie. 4
*/

// { Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends