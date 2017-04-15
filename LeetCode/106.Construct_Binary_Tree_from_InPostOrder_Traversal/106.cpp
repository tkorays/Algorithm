#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
TreeNode* build(vector<int>& postorder, int pstart, int pend,
        vector<int> inorder, int istart, int iend) {
        if(pstart <= pend) {
            int i;
            for(i = istart; i <= iend && inorder[i] != postorder[pend]; i++);
            TreeNode* n = new TreeNode(postorder[pend]);
            int ll = i - istart, lr = iend - i;
            n->left = build(postorder, pstart, pstart + ll - 1, inorder, istart, i - 1);
            n->right = build(postorder,  pstart + ll, pend - 1, inorder, i+1, iend);
            return n;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() -1);
    }
};