#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int heap[MAX];
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(KthLargest *obj, int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;
        if(obj->heap[parent] > obj->heap[i])
        {
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapifyDown(KthLargest *obj, int i)
{
    int smallest = i;

    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if(right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

void insert(KthLargest *obj, int val)
{
    obj->heap[obj->size] = val;
    heapifyUp(obj, obj->size);
    obj->size++;

    if(obj->size > obj->k)
    {
        obj->heap[0] = obj->heap[obj->size - 1];
        obj->size--;
        heapifyDown(obj, 0);
    }
}

KthLargest* KthLargestCreate(int k, int nums[], int numsSize)
{
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++)
        insert(obj, nums[i]);

    return obj;
}

int add(KthLargest* obj, int val)
{
    insert(obj, val);
    return obj->heap[0];
}
