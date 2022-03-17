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
    int maxDepth(TreeNode* root) {
        return getMaxDepth(root);
    }
    
    int getMaxDepth(TreeNode* root) {
        if(!root) return 0;
        
        if(!root -> left && !root -> right) return 1;
        
        return 1 + max(getMaxDepth(root -> left), getMaxDepth(root -> right));
    }
};