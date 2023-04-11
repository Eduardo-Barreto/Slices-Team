#include "createObjetcs.h"

void setup()
{
    com.write("Bololo iniciado!");
    com.waitForCommand();
    if (com.isCommand("calibrate"))
    {
        com.write("Calibrando...");
    }

    com.write("Iniciando...");
}

void loop()
{
}
