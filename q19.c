int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currMax = 0, max_so_far = nums[0];
    int currMin = 0, min_so_far = nums[0];

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        currMax = (nums[i] > currMax + nums[i]) ? nums[i] : currMax + nums[i];
        if (currMax > max_so_far) max_so_far = currMax;

        currMin = (nums[i] < currMin + nums[i]) ? nums[i] : currMin + nums[i];
        if (currMin < min_so_far) min_so_far = currMin;
    }

    if (max_so_far < 0) return max_so_far;

    int circularMax = totalSum - min_so_far;
    return (max_so_far > circularMax) ? max_so_far : circularMax;
}
