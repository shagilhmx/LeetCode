/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        
        markParent(root, parentTrack, target); //marking the parent and child in hmap.
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        
        q.push(target);
        vis[target] = true;
        int currLevel = 0;
        
        while(!q.empty()) {
            int s = q.size();
            
            if(currLevel++ == k) break;
            for(int i=0;i<s;i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !vis[curr -> left]) {
                    //for left nodes
                    q.push(curr -> left);
                    vis[curr -> left] = true;
                }
                if(curr -> right && !vis[curr -> right]) {
                    //for right nodes
                    q.push(curr -> right);
                    vis[curr -> right] = true;
                }
                if(parentTrack[curr] && !vis[parentTrack[curr]]) {
                    //for parent node.
                    q.push(parentTrack[curr]);
                    vis[parentTrack[curr]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr -> val);
        }
        return ans;
    }
    
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left) {
                parent[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right) {
                parent[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }
};