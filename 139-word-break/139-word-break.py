class Solution:
    def __inti__(self):
        self.Flag=[]   #for shortcut
    def wordBreak(self, s, dict):
        graph={}
        self.Flag=[]
        for i in dict:
            pos=0
            while s.find(i,pos)!=-1:
                p=s.find(i,pos)
                if p not in graph:
                    graph[p]=[p+len(i)]
                else:
                    if not p+len(i) in graph[p]:
                        graph[p].append(p+len(i))
                pos+=1
        return self.isgraphconnect(graph,0,len(s))
    def isgraphconnect(self,graph,pos,end):
            if pos in self.Flag:  #  shorcut if the pos is marked
                return False
            if pos==end:
                return True
            if pos not in graph:
                return False
            for  nextpos in graph[pos]:
                    t=self.isgraphconnect(graph,nextpos,end)
                    if t==False:
                        self.Flag.append(nextpos)  #mark if the pos can't touch the termination
                    else:
                        return True
            return False