/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* 方法1，直接利用题目21的合并两个链表函数 */
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
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* p = 0;
    int i;
    for(i=0; i<listsSize; i++) {
        p = mergeTwoLists(p, lists[i]);
    }
    return p;
}