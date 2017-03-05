/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists1(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode h, *p, *h1, *h2;
    p = &h;
    h1 = l1; h2 = l2;
    while(h1 || h2) {
        if(h1 && h2) 
            if(h1->val < h2->val) { p->next = h1; h1 = h1->next;}
            else {p->next = h2; h2 = h2->next;}
        else if(h1 && !h2) {p->next = h1; h1 = h1->next;}
        else if(h2 && !h1) {p->next = h2; h2 = h2->next;}
        p = p->next;
    }
    p->next = 0;
    return h.next;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode h, *p;
    p = &h;
    while(l1 && l2) {
        if(l1->val < l2->val) { p->next = l1; l1 = l1->next; }
        else { p->next = l2; l2 = l2->next; }
        p = p->next;
    }
    p->next = l1?l1:l2;
    return h.next;
}

/* 还可以递归实现 */

int main() {
    return 0;
}