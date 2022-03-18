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
    int search(vector<int>& inorder, int start, int end, int index) {
        for(int i=start;i<=end;i++)
            if(inorder[i] == index) return i;
        return -1;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = postorder.size()-1;
        return buildT(inorder, postorder, 0, index);
    }
    
    TreeNode* buildT(vector<int>& inorder, vector<int>& postorder, int start, int end) {
        if(start > end) return NULL;
        int curr = postorder[index--];
        TreeNode *newNode = new TreeNode(curr);
        //search the pos to insert the next node.
        int pos = search(inorder, start, end, curr);
        if(start == end) return newNode;
        newNode -> right = buildT(inorder, postorder, pos + 1, end);
        newNode -> left = buildT(inorder, postorder, start, pos - 1);
        return newNode;
    }
};