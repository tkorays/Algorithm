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

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* n;
        int level = 0, cnt = 1, i;
        if(root) q.push(root);
        while(!q.empty()) {
            int cntNew = 0;
            for(i = 0; i < cnt; i++) {  
                n = q.front(); q.pop();
                if(!n->left && !n->right) return level + 1;
                if(n->left) q.push((cntNew++,n->left));
                if(n->right) q.push((cntNew++,n->right));
            }
            cnt = cntNew;
            level++;
        }
        return level;
    }
};