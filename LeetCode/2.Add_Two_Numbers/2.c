/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
/*
 * mistakes:
 * 1) l1 is null but l2 still has nodes
 * 2) last overflow
 */ 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode *l1_node = l1;
    struct ListNode *l2_node = l2;
    struct ListNode *cur = &head;
    int overflow = 0, sum;
    head.next = 0;
    while(l1_node || l2_node) {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        if(l1_node && l2_node) {
            sum = l1_node->val + l2_node->val + overflow;
        }
        else if(l1_node) {
            sum = l1_node->val + overflow;
        }
        else {
            sum = l2_node->val + overflow;
        }
        sum = sum > 9 ? ((overflow = 1), sum - 10) : ((overflow = 0), sum);
        cur->val = sum;
        l1_node = l1_node ? l1_node->next : 0;
        l2_node = l2_node ? l2_node->next : 0;
    }
    if(overflow == 1) {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = 1;
    }
    cur->next = 0;
    return head.next;   
}

int main() {
    struct ListNode nodes[6];
    struct ListNode* result = 0;
    nodes[0].val = 2; nodes[0].next = nodes + 1;
    nodes[1].val = 4; nodes[1].next = nodes + 2;
    nodes[2].val = 3; nodes[2].next = 0;
    nodes[3].val = 5; nodes[3].next = nodes + 4;
    nodes[4].val = 6; nodes[4].next = nodes + 5;
    nodes[5].val = 4; nodes[5].next = 0;
    result = addTwoNumbers(nodes, nodes + 3);   
    if(result->val == 7 &&
        result->next->val == 0 &&
        result->next->next->val == 8)
        printf("PASS\n");
    else printf("FAIL\n");
    printf("%d->%d->%d\n", result->val, result->next->val, result->next->next->val);

    return 0;
}


