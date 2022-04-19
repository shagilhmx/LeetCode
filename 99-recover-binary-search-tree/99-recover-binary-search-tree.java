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
    vector<int> ans;
    int i = 0;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        sort(ans.begin(), ans.end());
        
        check(root);
    }
    
    void inorder(TreeNode* root) {
        if(!root)
            return;
        
        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }
    
    void check(TreeNode* root) {
        if(!root)
            return;
        
        check(root -> left);
        if(root -> val != ans[i])
            swap(root -> val, ans[i]);
        i++;
        check(root -> right);
    }
};