#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& num, int start, int end) {
        TreeNode* r = NULL;
        int mid;
        if(start <= end) {
            mid = (start + end + 1) / 2;
            r = new TreeNode(num[mid]);
            r->left = build(num, start, mid -1);
            r->right = build(num, mid + 1, end);
        }
        return r;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> num;
        while(head) {
            num.push_back(head->val);
            head = head->next;
        }
        return build(num, 0, num.size()-1);
    }
};
