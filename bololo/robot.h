class robotBase
{
public:
    bool isOn = false;

    void move(short leftVelocity, short rightVelocity)
    {
        leftMotor.run(leftVelocity);
        rightMotor.run(rightVelocity);
    }

    void stop()
    {
        leftMotor.stop();
        rightMotor.stop();
    }

    void off()
    {
        stop();
        digitalWrite(leftMotor.standByPin, LOW);
        isOn = false;
    }

    void on()
    {
        digitalWrite(leftMotor.standByPin, HIGH);
        isOn = true;
    }

    void die()
    {
        off();
        while (true)
            ;
    }
};