class Solution:
    def wordBreak(self, s, wordDict):
        # Modeled as a graph problem - every index is a vertex and every edge is a completed word             
        # The problem thus boils down to if a path exists.                                                    

        queue = collections.deque()                                                                           
        visited = set()                                                                                       
        queue.appendleft(0)                                                                                   
        visited.add(0)                                                                                        
        while len(queue) > 0:                                                                                 
            curr_index = queue.pop()                                                                          
            for i in range(curr_index, len(s)+1):                                                             
                if i in visited:                                                                              
                    continue                                                                                  
                if s[curr_index:i] in wordDict:                                                               
                    if i == len(s):                                                                           
                        return True                                                                           
                    queue.appendleft(i)                                                                       
                    visited.add(i)                                                                            
        return False   