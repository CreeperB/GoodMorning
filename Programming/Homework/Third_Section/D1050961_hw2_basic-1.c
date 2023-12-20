typedef struct {
    const int* reset;  // reset array won't be shuffled
    int* deck;         // the array would be shuffled
    int size;          // array size for above
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));  // malloc object of solution
    obj->size = numsSize;
    obj->reset = (int*)malloc(sizeof(int) * obj->size);  // malloc reset array
    obj->deck = (int*)malloc(sizeof(int) * obj->size);   // malloc deck array
    memcpy(obj->reset, nums, sizeof(int) * obj->size);   // memcpy nums to reset array
    memcpy(obj->deck, nums, sizeof(int) * obj->size);    // memcpy nums to deck array
    return obj;
}

int* solutionReset(Solution* obj, int* returnSize) {  // return reset array
    *returnSize = obj->size;
    return obj->reset;
}

void swap(int* a, int* b) {  // swap two element
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* solutionShuffle(Solution* obj, int* returnSize) {
    *returnSize = obj->size;
    for (int i = 0; i < obj->size; i++) {  // random swap to shuffle deck
        swap(&obj->deck[i], &obj->deck[rand() % obj->size]);
    }
    return obj->deck;
}

void solutionFree(Solution* obj) {
    free(obj);  // free object
}