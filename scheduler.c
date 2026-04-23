#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "parser.h"

MinHeap* heap;

void initScheduler() {
    heap = createHeap(10);
}

void scheduleRequest(char* priorityHeader, int id) {
    Request r;
    r.id = id;
    r.priority = parsePriority(priorityHeader);
    insertHeap(heap, r);
}

Request getNextRequest() {
    return extractMin(heap);
}

void cleanupScheduler() {
    freeHeap(heap);
}