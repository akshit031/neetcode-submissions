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
    bool validate(TreeNode* node, long long min_bound, long long max_bound) {
        if (node == nullptr) return true;
        if (node->val <= min_bound || node->val >= max_bound) {
            return false;
        }
        return validate(node->left, min_bound, node->val) && 
               validate(node->right, node->val, max_bound);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return validate(root, INT_MIN, INT_MAX);
    }
};
