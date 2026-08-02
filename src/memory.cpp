#include "Arduino.h"
#include "memory.h"

MemoryPoint memoryMap[MAX_MEMORY];

int memoryCount = 0;

//------------------------------------------

void saveObstacle(int x, int y)
{
    if(memoryCount >= MAX_MEMORY)
        return;

    memoryMap[memoryCount].x = x;
    memoryMap[memoryCount].y = y;
    memoryMap[memoryCount].cliff = false;

    memoryCount++;
}

//------------------------------------------

void saveCliff(int x, int y)
{
    if(memoryCount >= MAX_MEMORY)
        return;

    memoryMap[memoryCount].x = x;
    memoryMap[memoryCount].y = y;
    memoryMap[memoryCount].cliff = true;

    memoryCount++;
}

//------------------------------------------

bool isKnownDanger(int x, int y)
{
    for(int i=0;i<memoryCount;i++)
    {
        if(abs(memoryMap[i].x-x)<=1 &&
           abs(memoryMap[i].y-y)<=1)
        {
            return true;
        }
    }

    return false;
}

//------------------------------------------

void printMemory()
{
    Serial.println("----- Memory -----");

    for(int i=0;i<memoryCount;i++)
    {
        Serial.print("X:");

        Serial.print(memoryMap[i].x);

        Serial.print(" Y:");

        Serial.print(memoryMap[i].y);

        Serial.print(" ");

        if(memoryMap[i].cliff)
            Serial.println("CLIFF");
        else
            Serial.println("OBSTACLE");
    }

    Serial.println("------------------");
}
