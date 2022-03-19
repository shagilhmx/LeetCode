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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return nullptr;
        else if(n == 1) return new TreeNode(nums[0]); //if there is only one node.
        else return makeBST(nums, 0, n - 1);
    }
    
    TreeNode* makeBST(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        else if(start == end) { //if start index == end index, then return inserted node.
            TreeNode* newNode = new TreeNode(nums[start]);
            return newNode;
        }
        
        int mid = (end + start) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        
        newNode -> left = makeBST(nums, start, mid - 1);
        newNode -> right = makeBST(nums, mid + 1, end);
        
        return newNode;
    }
};