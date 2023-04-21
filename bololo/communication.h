#include <BluetoothSerial.h>

class communicationHandler
{
private:
    BluetoothSerial SerialBT;

public:
    String lastCommand = "";

    communicationHandler()
    {
        BluetoothSerial SerialBT;
    }

    void init()
    {
        SerialBT.begin("Bololo");
        Serial.begin(115200);
        while (!Serial)
            ;
    }

    String read()
    {
        lastCommand = "";
        if (SerialBT.available())
        {
            lastCommand = SerialBT.readStringUntil('\n');
        }

        if (Serial.available())
        {
            lastCommand = Serial.readStringUntil('\n');
        }
        lastCommand.toUpperCase();
        return lastCommand;
    }

    String waitForCommand()
    {
        lastCommand = "";
        while (lastCommand == "")
        {
            lastCommand = read();
        }
        return lastCommand;
    }

    void write(String message)
    {
        Serial.print(message);
        SerialBT.print(message);
    }

    void write(int message)
    {
        write(String(message));
    }

    void write(unsigned long message)
    {
        write(String(message));
    }

    void write(float message, int precision = 4)
    {
        write(String(message, precision));
    }

    void write(double message, int precision = 4)
    {
        write(String(message, precision));
    }

    void writeln()
    {
        write("\n");
    }

    void writeln(String message)
    {
        write(message);
        write("\n");
    }

    void writeln(int message)
    {
        writeln(String(message));
    }

    void writeln(unsigned long message)
    {
        writeln(String(message));
    }

    void writeln(float message, int precision = 4)
    {
        writeln(String(message, precision));
    }

    void writeln(double message, int precision = 4)
    {
        writeln(String(message, precision));
    }

    bool isCommand(String command)
    {
        return strstr(lastCommand.c_str(), command.c_str());
    }
};
