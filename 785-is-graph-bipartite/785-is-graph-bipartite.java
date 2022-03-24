class Solution {
    public boolean isBipartite(int[][] graph) {
        //DFS
        int n = graph.length;
        int[] color = new int[n];
        
        for(int i=0;i<n;i++) color[i] = -1;
        
        for(int i=0;i<n;i++)
            if(color[i] == -1)
                if(dfsCheck(i, graph, color) == false) return false;
            
        return true;
    }
    
    boolean dfsCheck(int node, int[][] graph, int[] color) {
        if(color[node] == -1) color[node] = 0;
        
        for(int u : graph[node]) {
            if(color[u] == -1) {
                color[u] = 1 - color[node];
                if(dfsCheck(u, graph, color) == false) return false;
            }
            else {
                if(color[u] == color[node]) return false;
            }
        }
        return true;
    }
}