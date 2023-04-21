class motor
{
private:
    byte IN1Pin;
    byte IN2Pin;
    byte pwmPin;
    byte pwmChannel;

public:
    byte standByPin;
    short velocity = 0;
    short lastVelocity = 0;
    unsigned long timeToApply = 0;

    motor(byte standByPin, byte IN1Pin, byte IN2Pin, byte pwmPin, byte pwmChannel)
    {
        this->standByPin = standByPin;
        this->IN1Pin = IN1Pin;
        this->IN2Pin = IN2Pin;
        this->pwmPin = pwmPin;
        this->pwmChannel = pwmChannel;
        this->init();
    }

    void init()
    {
        pinMode(standByPin, OUTPUT);
        pinMode(IN1Pin, OUTPUT);
        pinMode(IN2Pin, OUTPUT);

        ledcSetup(pwmChannel, 5000, 8);
        ledcAttachPin(pwmPin, pwmChannel);

        digitalWrite(standByPin, HIGH);
    }

    void run(short _velocity)
    {
        constrain(_velocity, -100, 100);

        if (_velocity * lastVelocity < 0)
        {
            ledcWrite(pwmChannel, 0);

            if (_velocity > 0)
            {
                digitalWrite(IN2Pin, LOW);
                digitalWrite(IN1Pin, HIGH);
            }
            else
            {
                digitalWrite(IN1Pin, LOW);
                digitalWrite(IN2Pin, HIGH);
            }
            timeToApply = millis() + 30;
            this->lastVelocity = _velocity;
            return;
        }

        if (lastVelocity == 0)
        {
            lastVelocity = _velocity;
            if (_velocity > 0)
            {
                digitalWrite(IN2Pin, LOW);
                digitalWrite(IN1Pin, HIGH);
            }
            else
            {
                digitalWrite(IN1Pin, LOW);
                digitalWrite(IN2Pin, HIGH);
            }
        }
        else if (millis() < timeToApply)
            return;

        this->velocity = (uint8_t)(constrain(map(abs(lastVelocity), 0, 100, 0, 255), 0, 255));
        ledcWrite(pwmChannel, this->velocity);
        this->lastVelocity = _velocity;
    }

    void stop()
    {
        ledcWrite(pwmChannel, 0);
        this->velocity = 0;
    }
};
