#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* padList(struct Node* head, int diff) {
    while (diff--) {
        struct Node* newNode = createNode(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node* addSameSize(struct Node* l1, struct Node* l2, int* carry) {
    if (l1 == NULL)
        return NULL;

    struct Node* result = createNode(0);

    result->next = addSameSize(l1->next, l2->next, carry);

    int sum = l1->data + l2->data + *carry;
    *carry = sum / 10;
    result->data = sum % 10;

    return result;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    if (len1 < len2)
        l1 = padList(l1, len2 - len1);
    else if (len2 < len1)
        l2 = padList(l2, len1 - len2);

    int carry = 0;
    struct Node* result = addSameSize(l1, l2, &carry);

    if (carry) {
        struct Node* newNode = createNode(carry);
        newNode->next = result;
        result = newNode;
    }

    return result;
}
