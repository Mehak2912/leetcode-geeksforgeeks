#include <stdio.h>
int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};
    for(int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;
    int maxFreq = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    int maxCount = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq)
            maxCount++;
    int intervals = (maxFreq - 1) * (n + 1) + maxCount;
    return (size > intervals) ? size : intervals;
}
int main() {
    char tasks[] = {'A','A','A','B','B','B'};
    int n = 2;
    int size = sizeof(tasks)/sizeof(tasks[0]);
    printf("Minimum CPU intervals: %d", leastInterval(tasks, size, n));
}
