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
    bool isSymmetric(TreeNode* root) {
        if(helper(root -> left, root -> right)) 
            return true;
        return false;
    }
    
    bool helper(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        else if(!a || !b) return false;
        else if(a -> val != b -> val) return false;
        return (helper(a -> left, b -> right) && helper(a -> right, b -> left));
    }
};