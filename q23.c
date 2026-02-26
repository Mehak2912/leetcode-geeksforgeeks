#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to detect cycle
bool hasCycle(struct Node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast)           // cycle detected
            return true;
    }

    return false;   // no cycle
}
