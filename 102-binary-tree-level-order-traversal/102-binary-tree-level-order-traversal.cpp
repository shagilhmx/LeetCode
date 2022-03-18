/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root) return {};
        
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while(n--) {
                TreeNode *curr = q.front();
                temp.push_back(curr -> val);
                q.pop();
                
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};