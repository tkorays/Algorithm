#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* n, next(0), *pNext = &next;
        if(root) st.push(root);
        while(!st.empty()) {
            n = st.top(); st.pop();
            pNext->left = NULL;
            pNext->right = n;
            pNext = n;
            if(n->right) st.push(n->right);
            if(n->left) st.push(n->left);
        }
    }
};
