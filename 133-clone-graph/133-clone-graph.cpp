/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp; //to check does we have the copy of the graph, and the node is not repeated more than once.
public:
    Node* cloneGraph(Node* node) {
        //using bfs.
        if(!node) return NULL;
        
        Node* first = new Node(node -> val, {}); //create a copy of the graph.
        mp[node] = first;
        
        queue<Node*> q; //for bfs.
        q.push(node); //push first node to queue.
        
        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            
            for(auto adj : curr -> neighbors) {
                if(mp.find(adj) == mp.end()) {
                    mp[adj] = new Node(adj -> val, {}); //create a copy.
                    q.push(adj);
                }
                mp[curr] -> neighbors.push_back(mp[adj]); //in current node push adj node.
            }
        }
        return mp[node];
    }
};