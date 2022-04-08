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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root)
            return "";
        
        vector<int> paths;
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue); //find lca.
        
        string left="";
        find1(startValue, lca, left); //getting distance from left node to root.
        
        string right="";
        find2(destValue, lca, right); //getting distance from right node to root.
        
        reverse(right.begin(), right.end());
        
        return left + right; //return combination of both.
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(!root || root -> val == p || root -> val == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode *right = lowestCommonAncestor(root -> right, p, q);
        
        if(!left) return right;
        if(!right) return left;
        else return root; //both are not null then we return root or node itself.
    }
    
    bool find1(int p, TreeNode* root, string& s) {
        if(!root)
            return false;
        
        if(root -> val == p)
            return true;
        
        if(find1(p, root -> left, s) || find1(p, root -> right, s)) {
            s += "U";
            return true;
        }
        return false;
    }
    
    bool find2(int p, TreeNode* root, string& s) {
        if(!root)
            return false;
        
        if(root -> val == p)
            return true;
        
        if(find2(p, root -> left, s)) {
            s += "L";
            return true;
        }
        
        else if(find2(p, root -> right, s)) {
            s += "R";
            return true;
        }
        return false;
    }
};

/*
    find the lowest common ancestor for any tree which is given in input and
    then compute the distance from start to that ancestor and ancestor to end.
*/