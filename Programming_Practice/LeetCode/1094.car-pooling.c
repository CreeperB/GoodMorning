/*
 * @lc app=leetcode id=1094 lang=c
 *
 * [1094] Car Pooling
 */

// @lc code=start

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int road[1001] = {0};
    for (int i = 0; i < tripsSize; i++) {
        road[trips[i][1]] += trips[i][0];
        road[trips[i][2]] -= trips[i][0];
    }
    int judge = 0;
    for (int i = 0; i <= 1000; i++) {
        judge += road[i];
        if (judge > capacity)
            return false;
    }
    return true;
}

// @lc code=end
