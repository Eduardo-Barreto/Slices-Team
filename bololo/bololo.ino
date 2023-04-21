#include "createObjetcs.h"
#include "followLine.h"
#include "routines.h"
#include "logs.h"

void setup()
{
    com.init();
    com.writeln("Bololo iniciado!");

    while (!com.isCommand("START"))
    {
        com.waitForCommand();

        if (com.isCommand("CALIBRATE"))
        {
            calibrateSensors();
            showCalibration();
        }
    }

    loadCalibration();
    com.writeln("Iniciando...");
    showCalibration();
    robot.on();
    timeToCheckEnd = millis() + 10000;
}

void loop()
{
    log();
    followLine();
    checkEnd();
}
