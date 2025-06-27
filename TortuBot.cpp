#include "TortuBot.h"

#define IR_LEFT_PIN     18
#define IR_CENTER_PIN   19
#define IR_RIGHT_PIN    23
#define LED_PIN         5
#define BUZZER_PIN      2

#define MOTOR1_IN1 27
#define MOTOR1_IN2 32
#define MOTOR2_IN1 25
#define MOTOR2_IN2 26

#define ENCODER1_A 4
#define ENCODER1_B 35
#define ENCODER2_A 15
#define ENCODER2_B 34

TortuBot* global_bot_ptr = nullptr;


void TortuBot::begin() {
    pinMode(IR_LEFT_PIN, INPUT);
    pinMode(IR_CENTER_PIN, INPUT);
    pinMode(IR_RIGHT_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    pinMode(MOTOR1_IN1, OUTPUT);
    pinMode(MOTOR1_IN2, OUTPUT);
    pinMode(MOTOR2_IN1, OUTPUT);
    pinMode(MOTOR2_IN2, OUTPUT);

    stop();
}

int TortuBot::readLeftIR() {
    return digitalRead(IR_LEFT_PIN);
}

int TortuBot::readCenterIR() {
    return digitalRead(IR_CENTER_PIN);
}

int TortuBot::readRightIR() {
    return digitalRead(IR_RIGHT_PIN);
}

void TortuBot::setLED(bool on) {
    digitalWrite(LED_PIN, on ? HIGH : LOW);
}

void TortuBot::beep(int ms) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(ms);
    digitalWrite(BUZZER_PIN, LOW);
}

int TortuBot::readExt(int pin) {
    pinMode(pin, INPUT);
    return analogRead(pin);
}

void TortuBot::blinkLED(int times, int timeON, int timeOFF) {
    for (int i = 0; i < times; ++i) {
        digitalWrite(LED_PIN, HIGH);
        delay(timeON);
        digitalWrite(LED_PIN, LOW);
        delay(timeOFF);
    }
}

void TortuBot::playTone(int freq, int duration) {
    ledcAttach(BUZZER_PIN, freq, 8);
    ledcWriteTone(BUZZER_PIN, freq);
    delay(duration);
    ledcWriteTone(BUZZER_PIN, 0);
    ledcDetach(BUZZER_PIN);
}

void TortuBot::readAllIR(int* values) {
    if (!values) return;
    values[0] = digitalRead(IR_LEFT_PIN);
    values[1] = digitalRead(IR_CENTER_PIN);
    values[2] = digitalRead(IR_RIGHT_PIN);
}

void TortuBot::moveForward(int speed) {
    setM1(speed, true);
    setM2(speed, true);
}

void TortuBot::moveBackward(int speed) {
    setM1(speed, false);
    setM2(speed, false);
}

void TortuBot::turnLeft(int speed) {
    setM1(speed, false);
    setM2(speed, true);
}

void TortuBot::turnRight(int speed) {
    setM1(speed, true);
    setM2(speed, false);
}

void TortuBot::stop() {
    stopM1();
    stopM2();
}

void TortuBot::setM1(int speed, bool forward) {
    speed = constrain(speed, 0, 255);
    if (forward) {
        analogWrite(MOTOR1_IN1, speed);
        analogWrite(MOTOR1_IN2, 0);
    } else {
        analogWrite(MOTOR1_IN1, 0);
        analogWrite(MOTOR1_IN2, speed);
    }
}

void TortuBot::setM2(int speed, bool forward) {
    speed = constrain(speed, 0, 255);
    if (forward) {
        analogWrite(MOTOR2_IN1, speed);
        analogWrite(MOTOR2_IN2, 0);
    } else {
        analogWrite(MOTOR2_IN1, 0);
        analogWrite(MOTOR2_IN2, speed);
    }
}

void TortuBot::stopM1() {
    analogWrite(MOTOR1_IN1, 0);
    analogWrite(MOTOR1_IN2, 0);
}

void TortuBot::stopM2() {
    analogWrite(MOTOR2_IN1, 0);
    analogWrite(MOTOR2_IN2, 0);
}

void IRAM_ATTR encoder1_isr() {
    if (!global_bot_ptr) return;
        int A = digitalRead(ENCODER1_A);
        int B = digitalRead(ENCODER1_B);
    if (A == B) {
        global_bot_ptr->encoder1_count++;
    } else {
        global_bot_ptr->encoder1_count--;
    }
}

void IRAM_ATTR encoder2_isr() {
    if (!global_bot_ptr) return;
        int A = digitalRead(ENCODER2_A);
        int B = digitalRead(ENCODER2_B);
    if (A == B) {
        global_bot_ptr->encoder2_count++;
    } else {
        global_bot_ptr->encoder2_count--;
    }
}

void TortuBot::initEncoders() {
    pinMode(ENCODER1_A, INPUT_PULLUP);
    pinMode(ENCODER1_B, INPUT_PULLUP);
    pinMode(ENCODER2_A, INPUT_PULLUP);
    pinMode(ENCODER2_B, INPUT_PULLUP);

    encoder1_count = 0;
    encoder2_count = 0;

    lastState1A = digitalRead(ENCODER1_A);
    lastState2A = digitalRead(ENCODER2_A);

    global_bot_ptr = this;

    attachInterrupt(digitalPinToInterrupt(ENCODER1_A), encoder1_isr, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER2_A), encoder2_isr, CHANGE);
}

long TortuBot::readEncoder1() { 
    return encoder1_count; 
}

long TortuBot::readEncoder2() { 
    return encoder2_count; 
}

void TortuBot::resetEncoders() { 
    encoder1_count = 0; encoder2_count = 0; 
}