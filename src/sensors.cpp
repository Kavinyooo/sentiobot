#include "Arduino.h"
#include "config.h"
#include "sensors.h"

unsigned long obstacleStart = 0;
bool obstaclePresent = false;

//-----------------------------------------------------
// Measure Distance using Ultrasonic Sensor
//-----------------------------------------------------

long getDistance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);

    long distance = duration * 0.034 / 2;

    return distance;
}

//-----------------------------------------------------
// Obstacle Detection
//-----------------------------------------------------

bool detectObstacle()
{
    long distance = getDistance();

    if(distance > 0 && distance <= SAFE_DISTANCE)
        return true;

    return false;
}

//-----------------------------------------------------
// Human Detection
//-----------------------------------------------------

bool detectHuman()
{
    if(detectObstacle())
    {
        if(!obstaclePresent)
        {
            obstaclePresent = true;
            obstacleStart = millis();
        }

        if(millis() - obstacleStart < HUMAN_TIME)
        {
            return true;
        }
    }
    else
    {
        obstaclePresent = false;
    }

    return false;
}

//-----------------------------------------------------
// Cliff Detection
//-----------------------------------------------------

bool detectCliff()
{
    if(digitalRead(CLIFF_PIN) == LOW)
    {
        return true;
    }

    return false;
}
