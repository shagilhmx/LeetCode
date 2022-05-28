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
    int currPos = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, preorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* build(int index, int n, vector<int>& preorder, vector<int>& inorder) {
        if(index > n) return nullptr;
        
        int curr = preorder[currPos++];
        TreeNode* newNode = new TreeNode(curr);
        int pos = search(inorder, index, n, curr);
        if(index == n)
            return newNode;
            
        newNode -> left = build(index, pos - 1, preorder, inorder);
        newNode -> right = build(pos + 1, n, preorder, inorder);
            
        return newNode;
    }
    
    int search(vector<int>& inorder, int start, int end, int curr) {
        for(int i=start;i<=end;i++)
            if(inorder[i] == curr)
                return i;
        return -1;
    }
};