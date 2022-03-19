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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        
        return buildBST(preorder, i, INT_MAX);
    }
    
    TreeNode* buildBST(vector<int>& preorder, int& index, int upper_bound) {
        if(index == preorder.size() || preorder[index] > upper_bound) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[index++]);
        root -> left = buildBST(preorder, index, root -> val);
        root -> right = buildBST(preorder, index, upper_bound);
        
        return root;
    }
};