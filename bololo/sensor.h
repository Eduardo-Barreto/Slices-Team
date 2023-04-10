class sensor
{

private:
    byte sensorPin;

public:
    int raw;
    int minRead = 0;
    int maxRead = 1023;
    byte reading;
    byte threshold = 50;

    sensor(byte sensorPin)
    {
        this->sensorPin = sensorPin;
        this->init();
    }

    void init()
    {
        pinMode(sensorPin, INPUT);
    }

    byte read()
    {
        this->raw = analogRead(sensorPin);
        this->reading = map(raw, minRead, maxRead, 100, 0);
        return this->reading;
    }

    void calibrate()
    {
        read();
        this->maxRead = (this->raw > this->maxRead) ? this->raw : this->maxRead;
        this->minRead = (this->raw < this->minRead) ? this->raw : this->minRead;
    }

    bool isBlack()
    {
        read();
        return (this->reading < threshold);
    }
};