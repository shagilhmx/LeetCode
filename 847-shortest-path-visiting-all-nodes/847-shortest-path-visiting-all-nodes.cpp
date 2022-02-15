class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        /*
        use bfs with marking the visited nodes, with bit masking.
        we can't use tradition bfs as it will lead to cycles so, the program
         will get stuck and we can't use vector as it will increase the time complexity.
        */ 
        
        if(graph.size() == 1) return 0; // as there is only one node and we are on that itself.
        return helper(graph);
    }
    
    int helper(vector<vector<int>>& graph) {
        int totalNodes = graph.size();
        int endMask = (1 << totalNodes) - 1; 
        /* 1111, the node at when we know that we have covered all the nodes.*/
        
        queue<pair<int, pair<int, int>>> q; 
        /* holds three values, value of node, dist we took and bitmask.*/
        
        set<pair<int, int>> vis; 
        /*visited to check we have certain node again.*/
        
        for(int i=0;i<totalNodes;i++) {
            int mask = (1 << i); // 2^i;
            q.push({i, {0, mask}}); // q({value - ith node, {distance, mask}})
            vis.insert({i, mask}); //visited(ith-node, its mask value);
        }
        
        while(!q.empty()) { //until queue does not get empty we will visit all the nodes
            auto node = q.front();
            q.pop();
            int val = node.first, dist = node.second.first, mask = node.second.second;
            
            for(auto temp : graph[val]) { //now will be visiting all the child nodes of the val.
                int newMask = (mask | (1 << temp)); 
                /* now at starting if we have node 0
                then the mask for 0 -> 0001 and now 
                I come to node 1 -> 0010, then we have
                newMask as 0001 | 0010 = 0011*/
                if(newMask == endMask) return dist + 1; //if we are at end node;
                else if(vis.count({temp, newMask})) continue; 
                /*if we already visisted a node before with same mask.*/
                
                vis.insert({temp, newMask});
                q.push({temp, {dist + 1, newMask}});
            }
        }
        return 0;
    }
};