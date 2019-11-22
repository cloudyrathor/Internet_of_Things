class Voltage_sense
{
  public:
        float Raw_voltage;
        float Fine_voltage,temp;
        float Voltage_Sensor;

  public :
        void Setup_voltage(float voltage_sensor)
        { 
          Voltage_Sensor = voltage_sensor;
          pinMode(Raw_voltage,INPUT); 
          Read_voltage();
//          Serial.print("Voltage => "); 
//          Serial.println(Fine_voltage);      
        }

        void Read_voltage()
        {
          float Raw_voltage = analogRead(Voltage_Sensor);
          temp=Raw_voltage/4.092;
          Fine_voltage=(temp/10);
        }
};
