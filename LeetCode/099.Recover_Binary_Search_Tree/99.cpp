#include <cstdlib>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* preNode = new TreeNode(INT_MIN);
    void biu(TreeNode* root) {
        if(!root) return;
        biu(root->left);
        if(!first && preNode->val >= root->val) first = preNode;
        if(first && preNode->val >= root->val) second = root;
        preNode = root;
        biu(root->right);
    }
    void recoverTree(TreeNode* root) {
        biu(root);
        swap(first->val, second->val);
    }
};

int main() {

    return 0;
}