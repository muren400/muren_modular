#include <MCP4728.h>
#include <Wire.h>

MCP4728 dac;

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);  // initialize serial interface for print()

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    Wire.begin();
    dac.attatch(Wire, 22);
    dac.readRegisters();
    dac.selectVref(MCP4728::VREF::VDD, MCP4728::VREF::VDD, MCP4728::VREF::INTERNAL_2_8V, MCP4728::VREF::INTERNAL_2_8V);
    dac.selectPowerDown(MCP4728::PWR_DOWN::GND_100KOHM, MCP4728::PWR_DOWN::GND_100KOHM, MCP4728::PWR_DOWN::GND_100KOHM, MCP4728::PWR_DOWN::GND_100KOHM);
    dac.selectGain(MCP4728::GAIN::X1, MCP4728::GAIN::X1, MCP4728::GAIN::X2, MCP4728::GAIN::X2);

    dac.analogWrite(MCP4728::DAC_CH::A, 1000);
    dac.enable(true);

    dac.readRegisters();
    printStatus();
}

// the loop function runs over and over again forever
void loop() {
    static int count = 0;
    count += 100; 
    if (count > 4000)  count = 0;

    dac.analogWrite(MCP4728::DAC_CH::A, count);

    delay(10);
    dac.readRegisters();
    printStatus();
}

void printStatus()
{
    Serial.println("NAME     Vref  Gain  PowerDown  DACData");
    for (int i = 0; i < 4; ++i)
    {
        Serial.print("DAC");
        Serial.print(i, DEC);
        Serial.print("   ");
        Serial.print("    ");
        Serial.print(dac.getVref(i), BIN);
        Serial.print("     ");
        Serial.print(dac.getGain(i), BIN);
        Serial.print("       ");
        Serial.print(dac.getPowerDown(i), BIN);
        Serial.print("       ");
        Serial.println(dac.getDACData(i), DEC);

        Serial.print("EEPROM");
        Serial.print(i, DEC);
        Serial.print("    ");
        Serial.print(dac.getVref(i, true), BIN);
        Serial.print("     ");
        Serial.print(dac.getGain(i, true), BIN);
        Serial.print("       ");
        Serial.print(dac.getPowerDown(i, true), BIN);
        Serial.print("       ");
        Serial.println(dac.getDACData(i, true), DEC);
    }
    Serial.println(" ");
}