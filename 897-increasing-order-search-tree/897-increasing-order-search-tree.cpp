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
    TreeNode *newNode = new TreeNode(0);
    TreeNode *ptr = newNode;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return NULL;
        
        increasingBST(root->left);
        if(root){
            ptr->right = root;
            root->left = NULL;
            ptr = ptr -> right;
        }
        increasingBST(root->right);
        
        return newNode->right;
    }
};