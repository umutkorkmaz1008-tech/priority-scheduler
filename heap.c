#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(Request* a, Request* b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (Request*)malloc(sizeof(Request) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->arr[(index - 1) / 2].priority > heap->arr[index].priority) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left].priority < heap->arr[smallest].priority)
        smallest = left;

    if (right < heap->size && heap->arr[right].priority < heap->arr[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insertHeap(MinHeap* heap, Request r) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->arr = realloc(heap->arr, heap->capacity * sizeof(Request));
    }

    heap->arr[heap->size] = r;
    heapifyUp(heap, heap->size);
    heap->size++;
}

Request extractMin(MinHeap* heap) {
    Request root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

void freeHeap(MinHeap* heap) {
    free(heap->arr);
    free(heap);
}