#include <iostream>
#include <cstdlib>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 
    用Morris遍历效率更高点！
*/
class Solution {
public:
    bool compair(TreeNode* n1, TreeNode* n2) {
        if(!n1 && !n2) return true;
        if((n1 && !n2) || (!n1 && n2) || (n1->val != n2->val)) return false;
        if(!compair(n1->left, n2->right)) return false;
        if(!compair(n1->right, n2->left))  return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return compair(root->left, root->right);
    }
};