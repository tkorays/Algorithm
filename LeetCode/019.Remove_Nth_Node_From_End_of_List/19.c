/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5
*/


 struct ListNode {
     int val;
     struct ListNode *next;
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode start, *n1, *n2;
    int i;
    start.next = head;
    n1 = start.next;
    n2 = &start;

    for(i=0; i<n; i++) {
        n1 = n1->next;
    }
    while(n1 != 0) {
        n2 = n2->next;
        n1 = n1->next;
    }
    n2->next = n2->next==0?0:n2->next->next;
    return start.next;
}