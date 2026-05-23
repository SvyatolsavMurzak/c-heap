#include <stdio.h>
#include <stdlib.h>


void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void siftUp(int *arr, int i) {
    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void push(int **arr, int *size, int *capacity, int value) {
    if (*size == *capacity) {
        *capacity *= 2; 
        *arr = (int *)realloc(*arr, (*capacity) * sizeof(int));
    }
    (*arr)[*size] = value;
    siftUp(*arr, *size);
    (*size)++;
}

void pop(int *arr, int *size) {
    if (*size == 0) return; 
    arr[0] = arr[*size - 1];
    (*size)--;
    heapify(arr, *size, 0);
}

void buildHeap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int top(int *arr) {
    return arr[0];
}

int heapSize(int *size) {
    return *size;
}

int main() {
    int size = 0;
    int capacity = 2;
    int *arr = (int *)malloc(capacity * sizeof(int));
    push(&arr, &size, &capacity, 3); 
    push(&arr, &size, &capacity, 7); 
    push(&arr, &size, &capacity, 6); 
    push(&arr, &size, &capacity, 4); 
    push(&arr, &size, &capacity, 2); 
    push(&arr, &size, &capacity, 1); 


    printf("максимальный элемент: %d\n", arr[0]);


    free(arr);
    return 0;
}