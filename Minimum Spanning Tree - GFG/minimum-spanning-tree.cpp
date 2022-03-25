// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // we are getting the adj list as input.
        // we will declare three vectors parent, key and mst.
        vector<int> parent(V, -1), key(V, INT_MAX), mstSet(V, false);
        key[0] = 0;
        parent[0] = -1;
        
        for(int count=0;count<V-1;count++) {
            int minimal = INT_MAX, u;
            for(int v=0;v<V;v++)
                if(mstSet[v] == false && key[v] < minimal)
                    minimal = key[v], u = v;
            
            mstSet[u] = true;
            
            //iterate for all its adj vertices.
            for(auto it : adj[u]) {
                int node = it[0];
                int wt = it[1];
                
                if(mstSet[node] == false && wt < key[node])
                    parent[node] = u, key[node] = wt;
            }
        }
        
        int sum = 0;
        for(int el : key) sum += el;
        
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends