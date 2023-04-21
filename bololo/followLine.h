bool inCurve = true;

unsigned long timeToCheckEnd = 10000;

short velocity = 65,
      turnVelocity = 100;

void followLine()
{
    if (!robot.isOn)
        return;

    leftSensor.read();
    rightSensor.read();

    if (leftSensor.isWhite() && rightSensor.isWhite())
    {
        robot.move(velocity, velocity);
        return;
    }

    if (rightSensor.isBlack())
    {
        robot.move(-turnVelocity, turnVelocity);
        return;
    }

    if (leftSensor.isBlack())
    {
        robot.move(turnVelocity, -turnVelocity);
        return;
    }
}

void checkEnd()
{
    if (millis() < timeToCheckEnd)
        return;

    if (turnRightSensor.isBlack())
        return;

    com.writeln("Fim?");

    unsigned long timeout = millis() + 25;
    while (millis() < timeout)
    {
        if (turnLeftSensor.isWhite())
        {
            com.writeln("Encruzilhada.");
            timeToCheckEnd = millis() + 350;
            return;
        }
        followLine();
    }

    timeout = millis() + 1000;
    while (millis() < timeout)
    {
        followLine();
    }
    com.write("Fim!");
    robot.stop();
    robot.off();
    com.writeln("Robot stopped.");
    robot.die();
}
