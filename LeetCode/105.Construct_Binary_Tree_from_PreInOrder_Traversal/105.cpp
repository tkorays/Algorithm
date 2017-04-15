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
    TreeNode* build(vector<int>& preorder, int pstart, int pend,
        vector<int> inorder, int istart, int iend) {
            if(pstart <= pend) {
                int i;
                for(i = istart; i <= iend && inorder[i] != preorder[pstart]; i++);
                TreeNode* n = new TreeNode(preorder[pstart]);
                int ll = i - istart, lr = iend - i;
                n->left = build(preorder, pstart+1, pstart + ll, inorder, istart, i - 1);
                n->right = build(preorder,  pstart + ll + 1, pend, inorder, i+1, iend);
                return n;
            }
            return NULL;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};