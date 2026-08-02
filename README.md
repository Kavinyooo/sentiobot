# 🤖 RoboPet: Emotion-Inspired Autonomous Companion Robot

RoboPet is an autonomous robotic companion developed using **Arduino Uno** that mimics emotional behavior through adaptive navigation and environmental learning. Unlike conventional obstacle-avoiding robots, RoboPet develops a dynamic **trust level** based on its interactions with nearby objects and modifies its movement accordingly.

---

## 📖 Overview

The objective of RoboPet is to simulate simple emotional intelligence in an embedded robotic platform. Using ultrasonic sensing, cliff detection, environmental memory, and behavioral state transitions, the robot adapts its navigation strategy according to previous experiences.

The project combines embedded programming, sensor fusion, autonomous navigation, and behavioral algorithms to create a more interactive robotic system.

---

## ✨ Features

- Autonomous navigation along predefined paths
- Human detection using obstacle persistence
- Dynamic trust-based behavioral model
- Emotional state transitions (Normal, Cautious, Fearful)
- Cliff detection using IR sensors
- Environmental memory for obstacles and cliffs
- Adaptive navigation based on previous experiences
- LED status indication
- Obstacle memory and avoidance

---

## 🛠 Hardware Used

- Arduino Uno
- Ultrasonic Distance Sensor
- IR Cliff Sensor
- DC Geared Motors
- Motor Driver Module
- LEDs
- Chassis
- Battery Pack

---

## 🧠 Behavioral Model

### Trust Levels

#### High Trust
- Smooth navigation
- Normal movement speed
- Confident exploration

#### Medium Trust
- Periodic pauses while moving
- Increased environmental awareness

#### Low Trust
- Circular movement
- Stops frequently
- Waits until trust gradually rebuilds

---

## 👀 Human Detection

Objects detected for only a short duration are classified as humans.

The robot:

- Maintains a safe interaction distance
- Adjusts trust based on human proximity
- Learns from repeated encounters

---

## ⚠ Fear Response

The robot becomes frightened when:

- Repeated negative encounters occur
- A cliff is detected
- Trust decreases below predefined thresholds

Fear directly influences future navigation behavior.

---

## 🧠 Environmental Memory

The robot stores locations where it detects:

- Obstacles
- Cliffs

Previously recorded hazardous areas are avoided during future navigation cycles.

---

## 📂 Repository Structure

```text
robopet-emotion-robot/
│
├── src/
├── simulation/
├── docs/
├── images/
├── README.md
├── LICENSE
└── .gitignore
```

---

## Applications

- Human-Robot Interaction
- Behavioral Robotics
- Autonomous Navigation
- Educational Robotics
- Embedded Systems Research

---

## Future Improvements

- Voice Interaction
- Face Recognition
- Reinforcement Learning
- Wi-Fi Connectivity
- Mobile App Control
- SLAM-based Navigation

---

## Author

**Kavin Shah**
