class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //using dfs.
        List<Integer>[] graph = new ArrayList[numCourses];
        
        for(int i = 0; i < numCourses; i++) graph[i] = new ArrayList();
        
        // build adjecency list matrix
        for(int[] ordering : prerequisites) {
            graph[ordering[0]].add(ordering[1]);
        }
        
        // boolean array of visited courses
        boolean[] visited = new boolean[numCourses];
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(!cycleDetection(graph, i, visited, new boolean[numCourses])) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    boolean cycleDetection(List<Integer>[] graph, int course, boolean[] visited, boolean[] onStack) {
        visited[course] = true;
        onStack[course] = true;
        
        for(int num : graph[course]) {
            // if this child is already on stack
            // this means a cycle exists
            // return false
            if(onStack[num]) return false;
            
            // if have not visited num yet,
            // recursively run algorithm
            if(!visited[num]) {
                if(!cycleDetection(graph, num, visited, onStack)) {
                    return false;
                }
            }
        }
        
        // reset the course on the stack
        // to false 
        onStack[course] = false;
        
        return true;
    }
}