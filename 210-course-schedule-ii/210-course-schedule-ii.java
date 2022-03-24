class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adjList[numCourses];
        
        for(int i=0;i<prerequisites.size();i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++)
            if(!indegree[i]) q.push(i);
        
        if(q.size() == 0) return {};
        
        vector<int> ans;
            
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto u : adjList[node]) {
                indegree[u]--;
                if(!indegree[u]) q.push(u);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};