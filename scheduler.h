#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "heap.h"

void initScheduler();
void scheduleRequest(char* priorityHeader, int id);
Request getNextRequest();
void cleanupScheduler();

#endif