#include <stdio.h>
int searchInsert(int nums[], int n, int target) {
    int left = 0, right = n - 1;
    int ans = n;  // default position (insert at end)
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            right = mid - 1;  // move left to find first position
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, target;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);
    int result = searchInsert(nums, n, target);
    printf("%d\n", result);
    return 0;
}
