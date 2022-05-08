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
    int ans = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        
        return ans;
    }
    
    pair<int, int> solve(TreeNode* root) {
        if(root == NULL)
            return {0, 0};
        
        auto left = solve(root -> left);
        auto right = solve(root -> right);
        
        int sum = left.first + right.first + root -> val;
        int count = left.second + right.second + 1;
        
        if(round(sum/count) == root -> val)
            ans++;
        
        return {sum, count};
    }
};