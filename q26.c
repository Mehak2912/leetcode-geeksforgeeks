typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* curr = obj->head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    newNode->prev = NULL;
    if (obj->head) obj->head->prev = newNode;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj->size == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    Node* curr = obj->head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    Node* curr = obj->head;
    for (int i = 0; i < index; i++) curr = curr->next;
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node* toDelete = obj->head;
    if (index == 0) {
        obj->head = toDelete->next;
        if (obj->head) obj->head->prev = NULL;
    } else {
        for (int i = 0; i < index; i++) toDelete = toDelete->next;
        toDelete->prev->next = toDelete->next;
        if (toDelete->next) toDelete->next->prev = toDelete->prev;
    }
    free(toDelete);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}
