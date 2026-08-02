#ifndef MEMORY_H
#define MEMORY_H

#define MAX_MEMORY 20

struct MemoryPoint
{
    int x;
    int y;
    bool cliff;
};

void saveObstacle(int x, int y);

void saveCliff(int x, int y);

bool isKnownDanger(int x, int y);

void printMemory();

#endif
