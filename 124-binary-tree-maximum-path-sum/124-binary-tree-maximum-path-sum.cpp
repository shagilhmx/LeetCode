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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        
        maxPath(root, maxSum);
        
        return maxSum;
    }
    
    int maxPath(TreeNode* root, int& maxSum) {
        if(!root) return 0;
        
        // if we get negitive at maxPath(last nodes) then we return 0.
        int leftSum = max(0, maxPath(root -> left, maxSum));
        int rightSum = max(0, maxPath(root -> right, maxSum));
        
        maxSum = max(maxSum, leftSum + rightSum + root -> val);
        
        return root -> val + max(leftSum, rightSum);
    }
};