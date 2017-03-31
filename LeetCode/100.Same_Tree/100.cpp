class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;
        if (p && q) {
            if (p->val != q->val) return false;
            else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};