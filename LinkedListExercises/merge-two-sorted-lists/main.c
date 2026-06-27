/*You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list.
 * The list should be made by splicing together the nodes of the first two
 * lists. Return the head of the merged linked list.*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_list(struct ListNode *ll)
{
    while (ll) {
        printf("%d", ll->val);
        ll = ll->next;
    }
    printf("\n");
}

void *safe_malloc(size_t n)
{
    void *p = malloc(n);
    if (p == NULL) {
        perror("malloc fail.");
        abort();
    }
    return p;
}

struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2)
{
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *curr = &dummy;

    while (L1 && L2) {
        if (L1->val <= L2->val) {
            curr->next = L1;
            L1 = L1->next;
        } else {
            curr->next = L2;
            L2 = L2->next;
        }
        curr = curr->next;
    }

    curr->next =
        L1 ? L1 : L2; // if one linked list doesnt end, you can staple it on to
                      // the end as it obviously doesnt need sorting
    return dummy.next;
}

void free_ll(struct ListNode *ll)
{
    struct ListNode *temp;
    while (ll) {
        temp = ll;
        ll = ll->next;
        free(temp);
    }
}

int main(void)
{

    struct ListNode *A_head = safe_malloc(sizeof(struct ListNode));
    struct ListNode *A_second = safe_malloc(sizeof(struct ListNode));
    struct ListNode *A_third = safe_malloc(sizeof(struct ListNode));

    A_head->val = 1;
    A_head->next = A_second;
    A_second->val = 2;
    A_second->next = A_third;
    A_third->val = 4;
    A_third->next = NULL;

    struct ListNode *B_head = safe_malloc(sizeof(struct ListNode));
    struct ListNode *B_second = safe_malloc(sizeof(struct ListNode));
    struct ListNode *B_third = safe_malloc(sizeof(struct ListNode));

    B_head->val = 1;
    B_head->next = B_second;
    B_second->val = 3;
    B_second->next = B_third;
    B_third->val = 4;
    B_third->next = NULL;

    struct ListNode *merged = mergeTwoLists(A_head, B_head);
    print_list(merged);

    free_ll(merged); // only free once since i'm entangling the 2 linked lists
                     // together completely

    return 0;
}
