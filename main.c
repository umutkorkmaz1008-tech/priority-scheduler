#include <stdio.h>
#include "scheduler.h"

int main() {
    initScheduler();

    scheduleRequest("u=5", 1);
    scheduleRequest("u=1", 2);
    scheduleRequest("u=3", 3);

    printf("Sirayla islemler:\n");

    for (int i = 0; i < 3; i++) {
        Request r = getNextRequest();
        printf("Request ID: %d, Priority: %d\n", r.id, r.priority);
    }

    cleanupScheduler();
    return 0;
}