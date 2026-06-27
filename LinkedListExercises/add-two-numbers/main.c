
/* You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list. You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.*/

#include <stdio.h>
#include <stdlib.h>
#undef DEBUG

#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

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

struct ListNode *addTwoNumbers(struct ListNode *L1, struct ListNode *L2)
{
    struct ListNode dummy; // dummy on stack, dont need to free.
    dummy.next = NULL;
    struct ListNode *curr = &dummy; // dummy is used store the head of the sum linked list

    int carry = 0;

    while (L1 != NULL || L2 != NULL || carry != 0) {
        int digit_sum = carry + (L1 ? L1->val : 0) +
                        (L2 ? L2->val : 0); // add LL values only if they exist

        carry = digit_sum / 10;

        if (DEBUG_TEST) {
            static int i = 0;
            printf("digit_sum = %d @ node %d\n", digit_sum, i);
            printf("curr->val = %d\n", curr->val);
            i++;
        }

        struct ListNode *newNode = safe_malloc(sizeof(struct ListNode));

        newNode->next = NULL;
        newNode->val = digit_sum % 10;

        curr->next = newNode;
        curr = curr->next;

        if (L1) L1 = L1->next;
        if (L2) L2 = L2->next;
    }
    return dummy.next; // return the (pointer to the) first node of the number
}

void print_linked_list(struct ListNode *llist)
{
    while (llist != NULL) {
        printf("%d", llist->val);
        llist = llist->next;
    }
    printf("\n");
}

void free_linked_list(struct ListNode *llist)
{
    struct ListNode *temp;
    while (llist != NULL) {
        temp = llist;
        llist = llist->next;
        free(temp);
    }
}

int main(void)
{

    struct ListNode *A_head = NULL;
    struct ListNode *A_second = NULL;
    struct ListNode *A_third = NULL;

    A_head = safe_malloc(sizeof(struct ListNode));
    A_second = safe_malloc(sizeof(struct ListNode));
    A_third = safe_malloc(sizeof(struct ListNode));

    A_head->val = 2;
    A_head->next = A_second;

    A_second->val = 4;
    A_second->next = A_third;

    A_third->val = 3;
    A_third->next = NULL;

    struct ListNode *B_head = NULL;
    struct ListNode *B_second = NULL;
    struct ListNode *B_third = NULL;

    B_head = safe_malloc(sizeof(struct ListNode));
    B_second = safe_malloc(sizeof(struct ListNode));
    B_third = safe_malloc(sizeof(struct ListNode));

    B_head->val = 5;
    B_head->next = B_second;

    B_second->val = 6;
    B_second->next = B_third;

    B_third->val = 4;
    B_third->next = NULL;

    struct ListNode *sum_head = addTwoNumbers(A_head, B_head);
    print_linked_list(sum_head);

    free_linked_list(B_head);
    free_linked_list(A_head);
    free_linked_list(sum_head);

    return 0;
}
