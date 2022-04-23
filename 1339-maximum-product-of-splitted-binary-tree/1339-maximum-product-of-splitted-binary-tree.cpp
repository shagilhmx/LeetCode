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
    long long maxProd = INT_MIN;
    
    long long totalSum = 0;
    
    long long findSum(TreeNode* root) {
        if(!root)
            return 0;
        
        return root -> val + findSum(root -> left) + findSum(root -> right);
    }
    
    long long helper(TreeNode* root) {
        if(!root)
            return 0;
        
        long long left = helper(root -> left);
        long long right = helper(root -> right);
        
        long long subTreeSum = left + right + root -> val;
        
        long long temp = subTreeSum * (totalSum - subTreeSum);
        
        maxProd = max(maxProd, temp);
        
        return subTreeSum;
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum = findSum(root);
        
        helper(root);
        
        return (int)(maxProd % (long long)(1e9 + 7));
    }
};