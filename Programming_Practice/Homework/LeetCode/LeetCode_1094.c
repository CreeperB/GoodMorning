bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int road[1001] = {0};
    for (int i = 0; i < tripsSize; i++) {
        road[trips[i][1]] += trips[i][0];  // record in
        road[trips[i][2]] -= trips[i][0];  // record out
    }
    int judge = 0;
    for (int i = 0; i <= 1000; i++) {
        judge += road[i];  // change the passenger amount
        if (judge > capacity)
            return false;  // return false if over capacity
    }
    return true;  // return true if not over capacity
}