class Current_sense
{
  public:
        float sensitivity = 100;
        float offsetVoltage = 2500;
        double adcVoltage = 0;
        int Current_pin;
        float Raw_current = 0;
        double Fine_current= 0;
       

  public :
        void Setup_current(int current_pin)
        { 
          Current_pin = current_pin;
          pinMode(Current_pin,INPUT); 
          Read_current();
          Serial.print("Raw Current => "); 
//          Serial.println(Fine_current);      
        }

        void Read_current()
        {
          Raw_current = analogRead(Current_pin);
          Serial.println(Raw_current);
          adcVoltage = (Raw_current / 1023.0) * 5000;
          adcVoltage = adcVoltage - 2700;
          Fine_current=((adcVoltage - offsetVoltage) / sensitivity);
          delay(1000);
        }
};
