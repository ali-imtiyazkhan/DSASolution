class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        return build(preorder, inorderMap, preorderIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderMap, 
                    int& preorderIndex, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal];

        root->left = build(preorder, inorderMap, preorderIndex, left, inorderIndex - 1);
        root->right = build(preorder, inorderMap, preorderIndex, inorderIndex + 1, right);

        return root;
    }
};
