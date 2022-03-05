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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int flag = 1;
        
        q.push(root);
        
        while(!q.empty()) {
            vector<int> temp;
            int n = q.size();
            
            while(n--) {
                TreeNode* tempNode = q.front();
                temp.push_back(tempNode->val);
                q.pop();
                
                if(tempNode -> left) q.push(tempNode->left);
                if(tempNode -> right) q.push(tempNode->right);
            }
            
            if(flag%2 == 0) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag++;
        }
        return ans;
    }
};