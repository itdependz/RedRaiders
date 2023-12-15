#ifndef AutonSelector_h
#define AutonSelector_h

#include <AlfredoConnect.h>
#include <BluetoothSerial.h>
#include <Alfredo_NoU2.h>
#include <Arduino.h>
#include <Arm.h>

class AutonSelector {
  private:
    NoU_Drivetrain* drive;
    Arm* arm;
    String selected;

    void scoreTaxi();
    void scoreTaxiCharge();
    void scoreTwo();
    void scoreTwoGetOneOutSide();
    void scoreTwoGetOneInSide();

  public:
    AutonSelector(NoU_Drivetrain* drivetrain);
    void play(String auton);
}
