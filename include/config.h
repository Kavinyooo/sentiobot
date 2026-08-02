#ifndef CONFIG_H
#define CONFIG_H

// -----------------------------
// Motor Driver Pins (L298N)
// -----------------------------

#define ENA 5
#define IN1 6
#define IN2 7

#define ENB 9
#define IN3 10
#define IN4 11

// -----------------------------
// Ultrasonic Sensor
// -----------------------------

#define TRIG_PIN 2
#define ECHO_PIN 3

// -----------------------------
// IR Cliff Sensor
// -----------------------------

#define CLIFF_PIN 4

// -----------------------------
// LEDs
// -----------------------------

#define GREEN_LED 12
#define RED_LED 13

// -----------------------------
// Robot Parameters
// -----------------------------

#define SAFE_DISTANCE 25          // cm

#define HUMAN_TIME 1200           // milliseconds

#define TRUST_MAX 100
#define TRUST_MIN 0

#define TRUST_HIGH 70
#define TRUST_MEDIUM 40

#endif
