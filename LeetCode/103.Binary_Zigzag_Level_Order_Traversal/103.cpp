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
    vector<int> LevelTraversal(stack<TreeNode*>& s1, stack<TreeNode*>& s2, bool& ltor) {
        vector<int> result;
        ltor = !ltor;
        while(!s1.empty()) {
            TreeNode* n = s1.top();
            s1.pop();
            result.push_back(n->val);
            if(ltor) {
                if(n->right) s2.push(n->right);
                if(n->left) s2.push(n->left);
            } else {
                if(n->left) s2.push(n->left);
                if(n->right) s2.push(n->right);
            }
        }
        return result;
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        stack<TreeNode*> s1, s2;
        bool ltor = true;
        if(!root) return result;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) result.push_back(LevelTraversal(s1,s2, ltor));
            else result.push_back(LevelTraversal(s2,s1, ltor));
        }
        return result;
    }
};