bool shoudLogReads = false;
bool shoudLogVelocity = false;

void logReads()
{
    if (!shoudLogReads)
        return;

    com.write(turnLeftSensor.light);
    com.write("\t");
    com.write(leftSensor.light);
    com.write("\t");
    com.write(rightSensor.light);
    com.write("\t");
    com.write(turnRightSensor.light);
    com.write("\t");
}

void logVelocity()
{
    if (!shoudLogVelocity)
        return;

    com.write(leftMotor.lastVelocity);
    com.write("\t");
    com.write(rightMotor.lastVelocity);
    com.write("\t");
}

void handleCommands()
{
    com.read();

    if (com.lastCommand == "")
        return;

    if (com.isCommand("LOG:READ"))
    {
        shoudLogReads = !shoudLogReads;
        return;
    }

    if (com.isCommand("LOG:VEL"))
    {
        shoudLogVelocity = !shoudLogVelocity;
        return;
    }

    if (com.isCommand("TOGGLE"))
    {
        if (robot.isOn)
            robot.off();
        else
            robot.on();
    }
}

void log()
{
    handleCommands();
    logReads();
    logVelocity();
    if (shoudLogReads || shoudLogVelocity)
        com.writeln();
}
