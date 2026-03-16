#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->size = k;
    obj->front = -1;
    obj->rear = -1;
    return obj;
}

bool isEmpty(MyCircularDeque* obj) {
    return obj->front == -1;
}

bool isFull(MyCircularDeque* obj) {
    return ((obj->front == 0 && obj->rear == obj->size - 1) || 
           (obj->front == obj->rear + 1));
}

bool insertFront(MyCircularDeque* obj, int value) {
    if(isFull(obj))
        return false;

    if(obj->front == -1)
        obj->front = obj->rear = 0;
    else if(obj->front == 0)
        obj->front = obj->size - 1;
    else
        obj->front--;

    obj->arr[obj->front] = value;
    return true;
}

bool insertLast(MyCircularDeque* obj, int value) {
    if(isFull(obj))
        return false;

    if(obj->front == -1)
        obj->front = obj->rear = 0;
    else if(obj->rear == obj->size - 1)
        obj->rear = 0;
    else
        obj->rear++;

    obj->arr[obj->rear] = value;
    return true;
}

bool deleteFront(MyCircularDeque* obj) {
    if(isEmpty(obj))
        return false;

    if(obj->front == obj->rear)
        obj->front = obj->rear = -1;
    else if(obj->front == obj->size - 1)
        obj->front = 0;
    else
        obj->front++;

    return true;
}

bool deleteLast(MyCircularDeque* obj) {
    if(isEmpty(obj))
        return false;

    if(obj->front == obj->rear)
        obj->front = obj->rear = -1;
    else if(obj->rear == 0)
        obj->rear = obj->size - 1;
    else
        obj->rear--;

    return true;
}

int getFront(MyCircularDeque* obj) {
    if(isEmpty(obj))
        return -1;

    return obj->arr[obj->front];
}

int getRear(MyCircularDeque* obj) {
    if(isEmpty(obj))
        return -1;

    return obj->arr[obj->rear];
}
