#include <stdio.h>
#include <stdlib.h>

int recursiveBinarySearch(int *list, int start, int end, int key) {
    if (start > end) return -1;
    int mid = (start + end) / 2;

    if (list[mid] == key) return mid;
    else if (list[mid] > key) return recursiveBinarySearch(list, start, mid-1, key);
    else return recursiveBinarySearch(list, mid+1, end, key);
}

int iterativeBinarySearch(int *list, int size, int key) {
    int start = 0, end = size - 1, mid = (start + end) / 2;
    while (start <= end) {
        if (list[mid] == key) break;
        else if (list[mid] > key) end = mid - 1;
        else start = mid + 1;
        mid = (start + end) / 2; 
    }
    if (start > end) return -1;
    else return mid;
}

int main() {
    int ordered[] = {10, 15, 20, 45, 50, 51, 54, 72, 77, 100};
    int s = sizeof(ordered) / sizeof(ordered[0]);
    int recursiveIndex = recursiveBinarySearch(ordered, 0, s-1, 100);
    int iterativeIndex = iterativeBinarySearch(ordered, s, 100);
    printf("recursive: %d\niterative: %d\n", recursiveIndex, iterativeIndex);

    return 0;
}