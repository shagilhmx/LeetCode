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
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string ds;
        helper(root, ds + to_string(root -> val));
        
        return ans;
    }
    
    void helper(TreeNode* root, string ds) {
        if(!root -> left && !root -> right) {
            ans.push_back(ds);
            return;
        }
        
        if(root -> left)
            helper(root -> left, ds + "->" + to_string(root -> left -> val));
        if(root -> right)
            helper(root -> right, ds + "->" + to_string(root -> right -> val));
    }
};