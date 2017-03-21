
#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        struct ListNode n(0);
        struct ListNode* p0 = &n, *p1 = head, *p2 = &n;
        int cnt = 0;
        n.next = head;
        while(cnt < k) {
            p0 = p0->next;
            p1 = p1->next;
            cnt++;
        }
        while(p1 != NULL) {
            p0 = p0->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        n.next = p2->next;
        p2->next = NULL;
        p0->next = head;
        return n.next;
    }
};