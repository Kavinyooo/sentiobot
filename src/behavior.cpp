#include "Arduino.h"

#include "behavior.h"
#include "motion.h"
#include "memory.h"
#include "trust.h"
#include "sensors.h"

#include "config.h"

extern int robotX;
extern int robotY;

void decideBehavior()
{

    //--------------------------------
    // Dangerous Location
    //--------------------------------

    if(isKnownDanger(robotX,robotY))
    {
        Serial.println("Known Dangerous Area");

        turnRight();

        robotX++;

        return;
    }

    //--------------------------------
    // Cliff
    //--------------------------------

    if(detectCliff())
    {
        Serial.println("CLIFF");

        saveCliff(robotX,robotY);

        decreaseTrust(25);

        stopRobot();

        delay(500);

        moveBackward();

        delay(700);

        turnLeft();

        robotX--;

        return;
    }

    //--------------------------------
    // Human
    //--------------------------------

    if(detectHuman())
    {
        Serial.println("Human");

        increaseTrust(2);
    }

    //--------------------------------
    // Obstacle
    //--------------------------------

    else if(detectObstacle())
    {
        Serial.println("Obstacle");

        saveObstacle(robotX,robotY);

        decreaseTrust(5);

        turnRight();

        robotX++;

        delay(300);

        return;
    }

    //--------------------------------
    // Recover Trust
    //--------------------------------

    recoverTrust();

    //--------------------------------
    // Behaviour
    //--------------------------------

    switch(getEmotion())
    {

        case 2:

            digitalWrite(GREEN_LED,HIGH);
            digitalWrite(RED_LED,LOW);

            moveForward();

            break;

        case 1:

            digitalWrite(GREEN_LED,HIGH);
            digitalWrite(RED_LED,HIGH);

            moveForward();

            delay(150);

            stopRobot();

            delay(200);

            break;

        case 0:

            digitalWrite(GREEN_LED,LOW);
            digitalWrite(RED_LED,HIGH);

            moveCircle();

            delay(1500);

            stopRobot();

            delay(1000);

            break;
    }

    robotY++;

}
