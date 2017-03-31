/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode h(0), *p, g(0), *q;
        for (h.next = head, p = &h, q = &g; p->next; ) {
            if (p->next->val >= x) {
                q->next = p->next;
                q = q->next;
                p->next = q->next;
                continue;
            }
            p = p->next;
        }
        q->next = NULL;
        p->next = g.next;
        return h.next;
    }
};