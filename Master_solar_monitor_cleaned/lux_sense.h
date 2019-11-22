class Lux_sense
{
  public:
        float Raw_lux;
        float Fine_lux;
        float Lux_Sensor;

  public :
        void Setup_lux(float lux_sensor)
        { 
          Lux_Sensor = lux_sensor;
          pinMode(Lux_Sensor,INPUT); 
          Read_lux();
//          Serial.print("Raw Lux => ");
//          Serial.println(Fine_lux);    
        }

        void Read_lux()
        {
          Raw_lux = analogRead(Lux_Sensor);
          Fine_lux = map(Raw_lux,0,4095,0,100);
          delay(1000);
        }
};
