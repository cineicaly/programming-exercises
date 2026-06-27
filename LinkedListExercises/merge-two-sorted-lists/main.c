#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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
    if (L1 == NULL && L2 != NULL) {
        return L2;
    }
    if (L1 != NULL && L2 == NULL) {
        return L1;
    }

    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *curr = &dummy;

    while (L1 || L2) {

    }
    return dummy.next;
}

int main(void)
{

    struct ListNode *A_head = safe_malloc(sizeof(struct ListNode));
    struct ListNode *A_second = safe_malloc(sizeof(struct ListNode));
    struct ListNode *A_third = safe_malloc(sizeof(struct ListNode));

    struct ListNode *B_head = safe_malloc(sizeof(struct ListNode));
    struct ListNode *B_second = safe_malloc(sizeof(struct ListNode));
    struct ListNode *B_third = safe_malloc(sizeof(struct ListNode));

    return 0;
}
