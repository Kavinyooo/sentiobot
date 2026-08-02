#include "config.h"
#include "motion.h"
#include "sensors.h"
#include "trust.h"

int trust = 80;
int fearCount = 0;

bool cliffDetected = false;
bool obstacleDetected = false;

void setup()
{
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(CLIFF_PIN, INPUT);

    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    Serial.println("SentioBot Initialized");
}

void loop()
{
    //---------------------------------
    // Cliff Detection
    //---------------------------------

    if(detectCliff())
    {
        Serial.println("CLIFF");

        decreaseTrust(25);

        stopRobot();

        delay(400);

        moveBackward();

        delay(700);

        turnLeft();

        return;
    }

    //---------------------------------
    // Human Detection
    //---------------------------------

    if(detectHuman())
    {
        Serial.println("Human");

        increaseTrust(2);
    }

    //---------------------------------
    // Obstacle Detection
    //---------------------------------

    else if(detectObstacle())
    {
        Serial.println("Obstacle");

        decreaseTrust(5);

        turnRight();

        delay(300);
    }

    //---------------------------------
    // Recover Trust
    //---------------------------------

    recoverTrust();

    //---------------------------------
    // Behaviour
    //---------------------------------

    if(getEmotion() == 2)
    {
        moveForward();
    }

    else if(getEmotion() == 1)
    {
        moveForward();

        delay(150);

        stopRobot();

        delay(200);
    }

    else
    {
        moveCircle();

        delay(1500);

        stopRobot();

        delay(1000);
    }

    Serial.print("Trust : ");
    Serial.println(getTrust());

    delay(50);
}
