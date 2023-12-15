#include <AutonSelector.h>

AutonSelector::AutonSelector(NoU_Drivetrain* drivetrain, Arm* arm): drive(drivetrain), arm(arm) {}

void AutonSelector::play(String auton) {
  if (auton == "scoreTaxi") {
    scoreTaxi();
  }
  else if (auton == "scoreTaxiCharge") {
    scoreTaxiCharge();
  }
  else if (auton == "scoreTwo") {
    scoreTwo();
  }
  else if (auton == "scoreTwoGetOneOutSide") {
    scoreTwoGetOneOutSide();
  }
  else if (auton == "scoreTwoGetOneInSide") {
    scoreTwoGetOneInSide();
  }
  else {
    scoreTaxi();
  }
}

void AutonSelector::scoreTaxi() {
  arm.set('h');
  drive->tankDrive(0, 0);
  delay(500);
  arm->setIntake(-1);
  delay(500);
  arm->setIntake(0);
  arm.set('s');
  drive->tankDrive(-0.5, -0.5);
  delay(3000);
  drive->set(0, 0);
}
void AutonSelector::scoreTaxiCharge() {
  arm.set('h');
  drive->tankDrive(0, 0);
  delay(500);
  arm->setIntake(-1);
  delay(500);
  arm->setIntake(0);
  arm.set('s');
  drive->tankDrive(-0.5, -0.5);
  delay(3000);
  drive->set(0.5, 0.5);
  delay(1200);
  drive->set(0,0);
}
void AutonSelector::scoreTwo() {
  arm.set('h');
  drive->tankDrive(0, 0);
  delay(500);
  arm->setIntake(-1);
  delay(500);
  arm->setIntake(0);
  arm.set('f');
  drive->tankDrive(-0.5, -0.5);
  arm->setIntake(1);
  delay(3000);
  arm.set('s');
  drive->tankDrive(0.5, 0.5);
  delay(2500);
  drive->tankDrive(0.25, 0.25);
  arm.set('m');
  delay(1000);
  drive->tankDrive(0, 0);
  delay(100);
  arm->setIntake(-1);
  delay(1000);
  arm->setIntake(0);
  arm.set('s');
  drive->set(0, 0);
  delay(300);
  drive->tankDrive(-1, -1);
  drive.set(1500);
  drive->tankDrive(0, 0);
}
void AutonSelector::scoreTwoGetOneOutSide() {
  scoreTwo();
  drive->tankDrive(0.5, -0.5);
  delay(100);
  drive->tankDrive(0, 0);
  arm.set('f');
  delay(40);
  arm->setIntake(1);
  drive->tankDrive(-0.5, -0.5);
  delay(500);
  drive->tankDrive(0, 0);
  arm.set('s');
}
void AutonSelector::scoreTwoGetOneInSide() {
  scoreTwo();
  drive->tankDrive(-0.5, 0.5);
  delay(100);
  drive->tankDrive(0, 0);
  arm.set('f');
  delay(40);
  arm->setIntake(1);
  drive->tankDrive(-0.5, -0.5);
  delay(500);
  drive->tankDrive(0, 0);
  arm.set('s');
}
