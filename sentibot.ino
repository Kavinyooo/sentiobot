#include "config.h"

#include "motion.h"
#include "sensors.h"
#include "trust.h"
#include "memory.h"
#include "behavior.h"

int robotX = 0;
int robotY = 0;

void setup()
{
    Serial.begin(9600);

    // ---------- Ultrasonic ----------
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    // ---------- Cliff Sensor ----------
    pinMode(CLIFF_PIN, INPUT);

    // ---------- LEDs ----------
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    // ---------- Motor Driver ----------
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    stopRobot();

    Serial.println();
    Serial.println("==============================");
    Serial.println("     SentioBot v1.0");
    Serial.println("==============================");
    Serial.println("Emotion-Inspired Robot");
    Serial.println("System Ready...");
    Serial.println();
}

void loop()
{
    // Main AI Decision Engine
    decideBehavior();

    // -------- Debug Information --------
    Serial.print("Trust : ");
    Serial.print(getTrust());

    Serial.print(" | Emotion : ");

    switch(getEmotion())
    {
        case 2:
            Serial.print("Happy");
            break;

        case 1:
            Serial.print("Cautious");
            break;

        case 0:
            Serial.print("Fear");
            break;
    }

    Serial.print(" | Position : (");

    Serial.print(robotX);

    Serial.print(",");

    Serial.print(robotY);

    Serial.print(")");

    Serial.print(" | Distance : ");

    Serial.print(getDistance());

    Serial.println(" cm");

    delay(50);
}
