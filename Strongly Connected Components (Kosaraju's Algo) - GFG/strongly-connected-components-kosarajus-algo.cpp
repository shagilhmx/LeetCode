// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(int node, stack<int>& st, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto u : adj[node])
            if(!vis[u])
                dfs(u, st, vis, adj);
                
        st.push(node);
    }
    
    void reverseDfs(int node, vector<int>& vis, vector<int> transpose[], vector<int>& ans) {
        ans.push_back(node);
        vis[node] = 1;
        for(auto u : transpose[node])
            if(!vis[u])
                reverseDfs(u, vis, transpose, ans);
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //topo sort
        vector<vector<int>> res;
        vector<int> temp;
        stack<int> st;
        vector<int> vis(V, 0);
        
        for(int i=0;i<V;i++)
            if(!vis[i])
                dfs(i, st, vis, adj);
                
        //transpose of the graph.
        vector<int> transpose[V];
        
        for(int i=0;i<V;i++) {
            vis[i] = 0;
            for(auto u : adj[i])
                transpose[u].push_back(i);
        }
        
        //go on the nodes according to their finishing time.
        int c = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            temp.clear();
            if(!vis[node]){
                reverseDfs(node, vis, transpose, temp);
                c++;
            }
            res.push_back(temp);
        }
        
        return c;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends