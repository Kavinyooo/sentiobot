#include "Arduino.h"
#include "config.h"
#include "motion.h"

void setSpeed(int leftSpeed, int rightSpeed)
{
    analogWrite(ENA, constrain(leftSpeed, 0, 255));
    analogWrite(ENB, constrain(rightSpeed, 0, 255));
}

void moveForward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    setSpeed(180,180);
}

void moveBackward()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    setSpeed(180,180);
}

void turnLeft()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    setSpeed(170,170);

    delay(300);
}

void turnRight()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    setSpeed(170,170);

    delay(300);
}

void stopRobot()
{
    analogWrite(ENA,0);
    analogWrite(ENB,0);

    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}

void moveCircle()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);

    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);

    setSpeed(220,90);
}
