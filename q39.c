#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
typedef struct {
    int num;
    int freq;
} Pair;
int compare(const void *a, const void *b)
{
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    return p2->freq - p1->freq; // descending order
}
int main()
{
    int nums[] = {1,1,1,2,2,3};
    int n = 6;
    int k = 2;
    Pair freq[MAX];
    int size = 0;
  
    for(int i = 0; i < n; i++)
    {
        int found = 0;
        for(int j = 0; j < size; j++)
        {
            if(freq[j].num == nums[i])
            {
                freq[j].freq++;
                found = 1;
                break;
            }
        }
        if(!found)
        {
            freq[size].num = nums[i];
            freq[size].freq = 1;
            size++;
        }
    }
    qsort(freq, size, sizeof(Pair), compare);
    for(int i = 0; i < k; i++)
        printf("%d ", freq[i].num);

    return 0;
}
