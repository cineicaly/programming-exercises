
/* You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list. You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void *safe_malloc(size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        perror("malloc fail.");
        abort();
    }
    return p;
}

struct ListNode *addTwoNumbers(struct ListNode *L1, struct ListNode *L2)
{
    int carry = 0;
    struct ListNode *curr = NULL, *result_head = NULL;
    result_head = malloc(sizeof(struct ListNode));
    curr = malloc(sizeof(struct ListNode));

    while (L1->next != NULL || L2->next != NULL || carry != 0) {
        int digit_sum = L1->val + L2->val + carry;

        if (digit_sum > 9)
            carry = digit_sum / 10;

        curr->val = digit_sum % 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        if (!newNode) {
            perror("failed alloc inside addTwoNumbers");
            return EXIT_FAILURE;
        }

        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;

        L1 = L1->next;
        L2 = L2->next;
    }

    return 
}

int main(void)
{

    struct ListNode *A_head = NULL;
    struct ListNode *A_second = NULL;
    struct ListNode *A_third = NULL;

    A_head = malloc(sizeof(struct ListNode));
    A_second = malloc(sizeof(struct ListNode));
    A_third = malloc(sizeof(struct ListNode));

    if (!A_head || !A_second || !A_third) {
        perror("more details");
        return EXIT_FAILURE;
    }

    A_head->val = 2;
    A_head->next = A_second;

    A_second->val = 4;
    A_second->next = A_third;

    A_third->val = 3;
    A_third->next = NULL;

    struct ListNode *B_head = NULL;
    struct ListNode *B_second = NULL;
    struct ListNode *B_third = NULL;

    B_head = malloc(sizeof(struct ListNode));
    B_second = malloc(sizeof(struct ListNode));
    B_third = malloc(sizeof(struct ListNode));

    if (!B_head || !B_second || !B_third) {
        perror("more details");
        return EXIT_FAILURE;
    }

    B_head->val = 5;
    B_head->next = B_second;

    B_second->val = 6;
    B_second->next = B_third;

    B_third->val = 4;
    B_third->next = NULL;

    return 0;
}
