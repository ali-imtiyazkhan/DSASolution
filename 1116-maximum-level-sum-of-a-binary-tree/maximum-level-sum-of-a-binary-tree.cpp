 #include <queue>
 #include <vector>
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxlevel = 1;
        int level=1;
        int maxsum = root->val;
        while(!q.empty()){
            int size = q.size();
            int sum=0;
            for(int i = 0 ;i<size; ++i){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum>maxsum){
                maxsum  = sum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
    }
};