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
  drive->tankDrive(-0.5, -0.5);
  delay(3000);
  drive->set(0, 0);
}
