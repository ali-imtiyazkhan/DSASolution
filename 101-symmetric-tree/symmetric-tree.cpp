class Solution {
public:
    bool areMirro(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;

        return areMirro(t1->left, t2->right) && areMirro(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return areMirro(root->left, root->right);
    }
};
