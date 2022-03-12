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
    long long int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
		if (root) q.push({root, 0});
		long long ans = 0;
		// set the start num of current level.
		long long cur_level_start_num = 0; 
		// a pointer to mark the most right node in current level.
		TreeNode* cur_level_end_node = root; 
		// a pointer to mark the most right node in next level.
		TreeNode* next_level_end_node = nullptr;
		
		while (!q.empty()) {
			pair<TreeNode*, int> cur = q.front(); q.pop();
			if (cur.first->left) {
				q.push({cur.first->left, (long long) 2*cur.second + 1});
				next_level_end_node = cur.first->left;
			}
			if (cur.first->right) {
				q.push({cur.first->right, (long long) 2*cur.second + 2});
				next_level_end_node = cur.first->right;
			}
			
			// if reached the most right node in current level (the end node of current level), update the result.
			if (cur.first == cur_level_end_node) {
				ans = std::max(ans, cur.second - cur_level_start_num + 1);
				// set the start num of next level (the num of the most left node in next level, which is the front of the queue).
				cur_level_start_num = q.front().second;
				// set the end node as the most right node in next level.
				cur_level_end_node = next_level_end_node;
			}
		}
		return ans;
    }
};