#include "Arduino.h"
#include "config.h"
#include "trust.h"

int trust = 80;

unsigned long lastRecovery = 0;

//----------------------------------------
// Increase Trust
//----------------------------------------

void increaseTrust(int amount)
{
    trust += amount;

    if(trust > TRUST_MAX)
        trust = TRUST_MAX;
}

//----------------------------------------
// Decrease Trust
//----------------------------------------

void decreaseTrust(int amount)
{
    trust -= amount;

    if(trust < TRUST_MIN)
        trust = TRUST_MIN;
}

//----------------------------------------
// Recover Trust Slowly
//----------------------------------------

void recoverTrust()
{
    if(millis() - lastRecovery > 5000)
    {
        increaseTrust(1);

        lastRecovery = millis();
    }
}

//----------------------------------------

int getTrust()
{
    return trust;
}

//----------------------------------------

int getEmotion()
{
    if(trust >= TRUST_HIGH)
        return 2;      // Happy

    if(trust >= TRUST_MEDIUM)
        return 1;      // Cautious

    return 0;          // Fear
}
