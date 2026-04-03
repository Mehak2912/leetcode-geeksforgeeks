#include <stdio.h>
#include <stdbool.h>
void dfs(int roomsSize, int* roomsColSize, int rooms[][1000], int room, int visited[]) {
    visited[room] = 1;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(roomsSize, roomsColSize, rooms, key, visited);
        }
    }
}
bool canVisitAllRooms(int roomsSize, int roomsColSize[], int rooms[][1000]) {
    int visited[1000] = {0};
    dfs(roomsSize, roomsColSize, rooms, 0, visited);
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}
