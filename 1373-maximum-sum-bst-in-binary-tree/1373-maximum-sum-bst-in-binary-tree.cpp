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
struct Info {
    int sum;
    bool isBST;
    int max;
    int min; 
};
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
    
    Info solve(TreeNode* root, int& maxSum) {
        //stuct (sum, isBst, max, min).
        if(root == NULL) return {0, true, INT_MIN, INT_MAX};
        
        Info L = solve(root -> left, maxSum);
        Info R = solve(root -> right, maxSum);
        
        Info BST;
        
        if(L.isBST && R.isBST && L.max < root -> val && R.min > root -> val) {
            int sum = R.sum + root -> val + L.sum;
            
            maxSum = max(maxSum, sum);
            
            return {sum, true, max(R.max, root -> val), min(L.min, root -> val)};
        } else return {0, false, 0, 0};
    }
};