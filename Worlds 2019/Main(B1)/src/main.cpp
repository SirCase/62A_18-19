
#include "..\..\Main()\include\Common\main.h"

void auton() {
  resetGyro();
  vex::task c(catapultControl);

  // spin intake inwards
  intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);

  // drive to cap to pick up ball
  encoderDrive(-2550, 50);
  wait(800);

  // drive back
  encoderDrive(2400, 50);

  intake.stop();

  // turn left
  gyroTurn(-90);

  // turnToFlag();

  // fire catapult
  firing = true;
  wait(1000);

  // turn right a little bit
  // turnToFlag();
  // gyroTurn(5);

  // drive to low flag
  //encoderDrive(2850, 50);
  //timedDrive(600, 50);

  //drive back
  //encoderDrive(-1000, 50);

  //turn right to face cap
  //gyroTurn(90);

  //drive to flip cap
  //intake.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
  //encoderDrive(-1500, 60);

  stopAll();
}

int main() {
  Competition.autonomous(auton);
  Competition.drivercontrol(defaultUserControl);
}