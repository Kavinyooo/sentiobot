#include "config.h"
#include "motion.h"
#include "sensors.h"

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
    if(detectCliff())
    {
        Serial.println("CLIFF DETECTED");

        stopRobot();

        delay(500);

        moveBackward();

        delay(700);

        turnLeft();

        return;
    }

    if(detectHuman())
    {
        Serial.println("Human Nearby");
    }

    if(detectObstacle())
    {
        Serial.println("Obstacle");
    }

    moveForward();

    delay(50);
}
