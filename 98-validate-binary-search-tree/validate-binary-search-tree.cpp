class Solution {
public:
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* node) {
        if (!node) return true;

        if (!inorder(node->left)) return false;

        if (prev && node->val <= prev->val) return false;
        prev = node;

        return inorder(node->right);
    }
};
