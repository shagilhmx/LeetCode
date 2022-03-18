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
    void flatten(TreeNode* root) {
        //preorder - root, left, right.
        if(!root || (!root -> right && !root -> left)) return;
        if(root -> left) {
            flatten(root -> left);
            TreeNode *temp = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            //now move to the end of the right branch and append the root -> right in temp.
            TreeNode *ptr = root -> right;
            while(ptr -> right) ptr = ptr -> right;
            ptr -> right = temp;
        }
        flatten(root -> right);
    }
};