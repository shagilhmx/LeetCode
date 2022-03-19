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
    map<int, vector<pair<int, int>>> hmap;
    //x -> vertical distance(col), y -> horizontal distance(row).
    void solve(TreeNode* root, int x, int y) {
        if(!root) return;
        
        hmap[x].push_back({y, root -> val});
        if(root -> left) solve(root -> left, x - 1, y + 1);
        if(root -> right) solve(root -> right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        vector<vector<int>> ans;
        
        for(auto el : hmap) {
            sort(el.second.begin(), el.second.end());
            vector<int> temp;
            for(auto each : el.second) temp.push_back(each.second);
            ans.push_back(temp);
        }
        return ans;
    }
};