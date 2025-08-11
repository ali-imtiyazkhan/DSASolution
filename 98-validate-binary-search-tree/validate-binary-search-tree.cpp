class Solution {
public:
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* node) {
        if (!node) return true;

        // Left subtree
        if (!inorder(node->left)) return false;

        // Current node check
        if (prev && node->val <= prev->val) return false;
        prev = node;

        // Right subtree
        return inorder(node->right);
    }
};
