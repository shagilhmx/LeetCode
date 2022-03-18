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
    int index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildT(preorder, inorder, index, preorder.size() - 1);
    }
    
    TreeNode* buildT(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if(start > end) return NULL;
        int curr = preorder[index++];
        TreeNode* newNode = new TreeNode(curr);
        //search the position to insert the new node.
        int pos = search(inorder, start, end, curr);
        if(start == end) return newNode;
        newNode -> left = buildT(preorder, inorder, start, pos - 1);
        newNode -> right = buildT(preorder, inorder, pos + 1, end);
        
        return newNode;
    }
    
    int search(vector<int>& inorder, int start, int end, int index) {
        for(int i=start;i<=end;i++) 
            if(inorder[i] == index) return i;
        return -1;
    }
};