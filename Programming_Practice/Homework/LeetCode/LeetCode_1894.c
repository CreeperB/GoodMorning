int chalkReplacer(int* chalk, int chalkSize, int k) {
    long sum = 0;
    for (int i = 0; i < chalkSize; i++) {
        sum += chalk[i];  // calculate the sum of chalk loop
    }
    k %= sum;  // mod k with sum to optimal
    for (int i = 0; i < chalkSize; i++) {
        k -= chalk[i];
        if (k < 0)
            return i;  // return the student no. when the chalk isn't enough
    }
    return 0;
}