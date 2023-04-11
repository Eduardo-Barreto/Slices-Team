class robot
{
public:
    void move(int8_t leftVelocity, int8_t rightVelocity)
    {
        leftMotor.run(leftVelocity);
        rightMotor.run(rightVelocity);
    }

    void stop()
    {
        leftMotor.stop();
        rightMotor.stop();
    }

    void die()
    {
        stop();
        digitalWrite(leftMotor.standByPin, LOW);
        while (true)
            ;
    }
};