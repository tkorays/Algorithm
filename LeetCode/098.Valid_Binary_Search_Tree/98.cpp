class Solution {
public:
    bool v(TreeNode* r, TreeNode*& p) {
        if (!r) return true;
        if (!v(r->left, p)) return false;
        if (p && r->val <= p->val) return false;
        return v(r->right, p = r);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* p = NULL;
        return v(root, p);
    }
};