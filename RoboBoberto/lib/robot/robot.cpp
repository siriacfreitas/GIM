#include "robot.hpp"

Robot::Robot() {
    // Inicia os pinos dos motores
    frontRight.setPins(0, 22, 24);
    frontLeft.setPins(0, 50, 52);
    backLeft.setPins(0, 51, 53);
    backRight.setPins(0, 33, 31);

    frontLeft.begin();
    frontRight.begin();
    backLeft.begin();
    backRight.begin();

}

Robot::~Robot() {}

void Robot::begin() {
  
}

void Robot::stop() {
    frontLeft.stop();
    frontRight.stop();
    backLeft.stop();
    backRight.stop();
}

void Robot::forward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.forward(100, vel);
            backLeft.forward(100, vel);
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::backward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.backward(100, vel);
            backLeft.backward(100, vel);
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::sidewaysRight(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.backward(100, vel);
            backLeft.backward(100, vel);
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::sidewaysLeft(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.forward(100, vel);
            backLeft.forward(100, vel);
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::rotateLeft(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.forward(0, vel);
        backLeft.backward(0, vel);
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.forward(100, vel);
            backLeft.backward(100, vel);
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::rotateRight(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.backward(0, vel);
        backLeft.forward(0, vel);
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.backward(100, vel);
            backLeft.forward(100, vel);
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveRightForward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.forward(0, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.forward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.forward(100, vel);
            frontRight.stop();
            backLeft.stop();
            backRight.forward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveRightBackward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.stop();
        frontRight.backward(0, vel);
        backLeft.backward(0, vel);
        backRight.stop();
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.stop();
            frontRight.backward(100, vel);
            backLeft.backward(100, vel);
            backRight.stop();

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveLeftForward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.stop();
        frontRight.forward(0, vel);
        backLeft.forward(0, vel);
        backRight.stop();
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.stop();
            frontRight.forward(100, vel);
            backLeft.forward(100, vel);
            backRight.stop();

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::moveLeftBackward(uint8_t goal, int16_t vel) {
    if (!goal) {
        frontLeft.backward(0, vel);
        frontRight.stop();
        backLeft.stop();
        backRight.backward(0, vel);
    } else {
        for (byte i = 0; i < goal; i++) {
            frontLeft.backward(100, vel);
            frontRight.stop();
            backLeft.stop();
            backRight.backward(100, vel);

            while (frontLeft.getFinished() or frontRight.getFinished() or
                   backLeft.getFinished() or backRight.getFinished()) {
                delay(1);
            }
        }
        stop();
    }
}

void Robot::smoothRotateLeft() {
    frontRight.backward(0, 200);
    backRight.backward(0, 200);

    backLeft.backward(0, 70);
    frontLeft.backward(0, 70);
}

void Robot::smoothRotateRight() {
    frontRight.backward(0, 70);
    backRight.backward(0, 70);

    backLeft.backward(0, 200);
    frontLeft.backward(0, 200);
}
