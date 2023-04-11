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
        lastCommand.toLowerCase();
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

    void writeln(String message)
    {
        Serial.println(message);
        SerialBT.println(message);
    }

    bool isCommand(String command)
    {
        return strstr(lastCommand.c_str(), command.c_str());
    }
};
