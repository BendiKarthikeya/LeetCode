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
    void collectInOrder(TreeNode* node, std::vector<int>& values) {
        if (node == nullptr) return;
        collectInOrder(node->left, values);
        values.push_back(node->val);
        collectInOrder(node->right, values);
    }

    void restoreInOrder(TreeNode* node, std::vector<int>::iterator& it) {
        if (node == nullptr) return;
        restoreInOrder(node->left, it);
        node->val = *it;
        ++it;
        restoreInOrder(node->right, it);
    }

    void recoverTree(TreeNode* root) {
        std::vector<int> values;
        collectInOrder(root, values);
        std::sort(values.begin(), values.end());
        auto it = values.begin();
        restoreInOrder(root, it);
    }
};
