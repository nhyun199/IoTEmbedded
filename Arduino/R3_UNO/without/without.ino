// Pin connected to the DS18B20 sensor
const int ds18b20Pin = 3; // Replace with your actual pin number

void sendCommand(byte cmd)
{
    for (int i = 0; i < 8; i++)
    {
        delayMicroseconds(10); // Write 0 bit
        if (bitRead(cmd, i))
        {
            noInterrupts();
            digitalWrite(ds18b20Pin, LOW);
            pinMode(ds18b20Pin, OUTPUT);
            delayMicroseconds(10);

            digitalWrite(ds18b20Pin, HIGH);
            interrupts();
            delayMicroseconds(55);
        }
        else
        {
            noInterrupts();
            digitalWrite(ds18b20Pin, LOW);
            pinMode(ds18b20Pin, OUTPUT);
            delayMicroseconds(65);
            digitalWrite(ds18b20Pin, HIGH);
            interrupts();
            delayMicroseconds(5);
        }
        // delayMicroseconds(1);       // Recovery time between bits
        // pinMode(ds18b20Pin, INPUT); // Release the data line
    }
}

bool resetSensor()
{
    // Pull the data line low for a reset pulse

    digitalWrite(ds18b20Pin, LOW);
    pinMode(ds18b20Pin, OUTPUT);

    delayMicroseconds(480); // Hold for 480us
    pinMode(ds18b20Pin, INPUT);
    delayMicroseconds(100); // Wait for DS18B20 to respond

    // Check if the DS18B20 pulled the line low (presence pulse)
    if (digitalRead(ds18b20Pin) == LOW)
    {
        delayMicroseconds(380); // Wait for presence pulse to end
        // Serial.println("Reset OK\n");
        return true;
    }
    else
    {
        // Serial.println("Reset NG\n");
        return false; // No DS18B20 detected
    }
}

byte readByte()
{
    byte byteRead = 0;
    for (int i = 0; i < 8; i++)
    {

        noInterrupts();
        pinMode(ds18b20Pin, OUTPUT);
        digitalWrite(ds18b20Pin, LOW);
        delayMicroseconds(3);

        pinMode(ds18b20Pin, INPUT);
        delayMicroseconds(10);
        byteRead |= (digitalRead(ds18b20Pin) << i);
        interrupts();
        delayMicroseconds(53);
    }
    return byteRead;
}

void setup()
{
    Serial.begin(9600);
}

void loop(){
    // goto Temp;
    // Serial.print("Serial Number: ");

    // // Reset the 1-Wire bus
    // if (!resetSensor())
    // {
    //     Serial.println("No DS18B20 detected.");
    //     delay(1000);
    //     return;
    // }

    // // Send command to read ROM
    // sendCommand(0x33); // Read ROM command

    // // Read the 64-bit ROM code
    // for (int i = 0; i < 8; i++) // Family code - serial number - crc : 8Bytes : 28-11-EF-48-F6-F6-3C-49
    // {
    //     byte byteRead = readByte();
    //     Serial.print(byteRead, HEX);
    //     if (i < 7)
    //         Serial.print('-'); // Print a dash between bytes
    // }
    // Serial.println();   
    
    resetSensor();

    sendCommand(0xCC);
    sendCommand(0x44);
    delay(1000);

    resetSensor();

    sendCommand(0xCC);
    sendCommand(0xBE);

    byte scratchPad[9];

    for(int i = 0; i < 9; i++)
    {
        byte byteRead = readByte();
        scratchPad[i] = byteRead;
        Serial.print(byteRead, HEX);
        if(i < 8)
            Serial.print('-');
    }
    Serial.println();
    // byte 0 : LSB, byte 1 : MSB
    // 앞의 두 바이트만 가져와서 십진수로 변환하고 더해서 온도로 표현?
    
    byte LSB = scratchPad[0];
    byte MSB = scratchPad[1];
    
    int16_t temperatureValue = (MSB << 8) | LSB;
    float temperature = (float)temperatureValue / 16;
    Serial.print(temperature);
}