// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool canColor(int node, int *color, bool graph[101][101], int V, int colorCode) {
    for(int vertices=0;vertices<V;vertices++) {
        if(vertices != node && graph[vertices][node] == 1 && color[vertices] == colorCode) return false;
    }
    return true;
}

bool helper(int node, int *color, int m, int V, bool graph[101][101]) {
    if(node == V) return true;
    
    for(int i=1;i<=m;i++) {
        if(canColor(node, color, graph, V, i)) {
            color[node] = i;
            if(helper(node + 1, color, m, V, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    
    if(helper(0, color, m, V, graph)) return true;
    else return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends