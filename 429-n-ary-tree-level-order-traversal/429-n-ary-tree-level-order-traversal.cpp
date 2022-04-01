/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while(n--) {
                Node* front = q.front();
                q.pop();

                if(front) {
                    temp.push_back(front->val);
                    for(int i=0;i<front->children.size();i++) {
                        q.push(front->children[i]);
                    }
                }
                else {
                    if(q.size() != 0)
                        q.push(NULL);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};