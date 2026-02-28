#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Detect and Remove Cycle
bool removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect Cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No cycle
    if (slow != fast)
        return false;

    // Step 2: Find start of cycle
    slow = head;

    // Special case: cycle starts at head
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Break cycle
    fast->next = NULL;

    return true;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    struct Node *cycleNode = NULL;

    // Create list
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        temp = createNode(x);

        if (head == NULL)
            head = temp;
        else
            prev->next = temp;

        prev = temp;
    }

    // Read position where cycle should start (for testing)
    scanf("%d", &pos);

    if (pos >= 0) {
        temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;

        prev->next = temp;  // create cycle
    }

    if (removeCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
