struct sensorCalibration
{
    short min = 4095;
    short max = 0;
};

class sensor
{

private:
    byte sensorPin;

public:
    short raw;
    sensorCalibration calibration;
    char light;
    byte threshold = 20;

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
        this->light = map(raw, calibration.min, calibration.max, 100, 0);
        return this->light;
    }

    void calibrate()
    {
        read();
        this->calibration.max = (this->raw > this->calibration.max) ? this->raw : this->calibration.max;
        this->calibration.min = (this->raw < this->calibration.min) ? this->raw : this->calibration.min;
    }

    bool isBlack()
    {
        read();
        return (this->light < threshold);
    }

    bool isWhite()
    {
        read();
        return (this->light > threshold);
    }
};
