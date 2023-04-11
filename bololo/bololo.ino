#include "routines.h"

void setup()
{
    com.init();
    com.writeln("Bololo iniciado!");

    while (!com.isCommand("start"))
    {
        com.waitForCommand();
        if (com.isCommand("calibrate"))
        {
            calibrateSensors();
            saveCalibration();
        }
    }

    loadCalibration();
    com.writeln("Iniciando...");
    showCalibration();
    robot.die();
}

void loop()
{
}
