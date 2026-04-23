#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int id;
    int priority;
} Request;

typedef struct {
    Request* arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity);
void insertHeap(MinHeap* heap, Request r);
Request extractMin(MinHeap* heap);
void freeHeap(MinHeap* heap);

#endif