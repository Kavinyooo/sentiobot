#include "config.h"

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
    obstacleDetected = detectObstacle();

    cliffDetected = detectCliff();

    updateTrust();

    decideBehavior();

    delay(50);
}
