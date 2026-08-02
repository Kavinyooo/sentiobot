#include "config.h"
#include "motion.h"
#include "sensors.h"
#include "trust.h"
#include "memory.h"

int robotX = 0;
int robotY = 0;

void setup()
{
    Serial.begin(9600);

    // Ultrasonic
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    // Cliff Sensor
    pinMode(CLIFF_PIN, INPUT);

    // LEDs
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    // Motor Driver
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    Serial.println("=================================");
    Serial.println(" SentioBot Initialized");
    Serial.println("=================================");
}

void loop()
{
    //----------------------------------------
    // CLIFF DETECTION
    //----------------------------------------

    if (detectCliff())
    {
        Serial.println("CLIFF DETECTED");

        saveCliff(robotX, robotY);

        decreaseTrust(25);

        stopRobot();

        delay(500);

        moveBackward();

        delay(700);

        turnLeft();

        robotX--;

        return;
    }

    //----------------------------------------
    // HUMAN DETECTION
    //----------------------------------------

    if (detectHuman())
    {
        Serial.println("Human Detected");

        increaseTrust(2);
    }

    //----------------------------------------
    // OBSTACLE DETECTION
    //----------------------------------------

    else if (detectObstacle())
    {
        Serial.println("Obstacle Detected");

        saveObstacle(robotX, robotY);

        decreaseTrust(5);

        turnRight();

        robotX++;

        delay(300);

        return;
    }

    //----------------------------------------
    // MEMORY CHECK
    //----------------------------------------

    if (isKnownDanger(robotX, robotY))
    {
        Serial.println("Known Dangerous Area");

        turnRight();

        robotX++;

        delay(300);

        return;
    }

    //----------------------------------------
    // TRUST RECOVERY
    //----------------------------------------

    recoverTrust();

    //----------------------------------------
    // BEHAVIOR ENGINE
    //----------------------------------------

    if (getEmotion() == 2)
    {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);

        moveForward();
    }

    else if (getEmotion() == 1)
    {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, HIGH);

        moveForward();

        delay(150);

        stopRobot();

        delay(200);
    }

    else
    {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);

        moveCircle();

        delay(1500);

        stopRobot();

        delay(1000);
    }

    //----------------------------------------
    // UPDATE POSITION
    //----------------------------------------

    robotY++;

    //----------------------------------------
    // DEBUG OUTPUT
    //----------------------------------------

    Serial.print("Trust : ");
    Serial.print(getTrust());

    Serial.print(" | Position : (");
    Serial.print(robotX);
    Serial.print(", ");
    Serial.print(robotY);
    Serial.println(")");

    delay(50);
}
