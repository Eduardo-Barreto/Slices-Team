class motor
{
private:
    byte standByPin;
    byte IN1Pin;
    byte IN2Pin;
    byte pwmPin;
    byte pwmChannel;

public:
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

        ledcSetup(pwmChannel, 1000, 8);
        ledcAttachPin(pwmPin, pwmChannel);

        digitalWrite(standByPin, HIGH);
    }

    void run(char velocity)
    {
        if (velocity > 0)
        {
            digitalWrite(IN2Pin, LOW);
            digitalWrite(IN1Pin, HIGH);
        }
        else
        {
            digitalWrite(IN1Pin, LOW);
            digitalWrite(IN2Pin, HIGH);
        }

        ledcWrite(pwmChannel, map(abs(velocity), 0, 100, 0, 255));
    }

    void die()
    {
        digitalWrite(IN1Pin, LOW);
        digitalWrite(IN2Pin, LOW);
        ledcWrite(pwmChannel, 0);
    }
};
