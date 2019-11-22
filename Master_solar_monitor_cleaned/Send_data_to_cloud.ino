
void checkData()
{
  for (uint8_t i = 1; i < 5; i++)
  {

    if (Firebase.getInt(firebaseData, path+"/voltage"+voltage))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      Serial.print("VALUE: ");
      if (firebaseData.dataType() == "int")
        Serial.println(firebaseData.intData());

//        if(firebaseData.dataPath() == "Solar_Panel_Parameter/voltage" && firebaseData.intData() == 1)
//        {
//          digitalWrite(2,HIGH);
//        }
//        else if(firebaseData.dataPath() == "Solar_Panel_Parameter/voltage" && firebaseData.intData() == 0)
//        {
//          digitalWrite(2,LOW);
//        }

      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }
}

void setData()
{
//  for (uint8_t i = 1; i < 5; i++)
//  {
Firebase.setInt(firebaseData, path+"/Date/voltage",voltage);
Firebase.setInt(firebaseData, path+"/Date/current",current);
Firebase.setInt(firebaseData, path+"/Date/lux",lux);
Firebase.setInt(firebaseData, path+"/Date/temperature",temp);
Firebase.setInt(firebaseData, path+"/Date/humidity",hum);
}

void updateData()
{
//  for (uint8_t i = 0; i < 5; i++)
//  {
    if (Firebase.getInt(firebaseData, path+"/voltage= ",voltage))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      Serial.print("VALUE: ");
      if (firebaseData.dataType() == "int")
        Serial.println(firebaseData.intData());
    }
    else if (Firebase.getInt(firebaseData, path+"/current= ",current))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      Serial.print("VALUE: ");
      if (firebaseData.dataType() == "int")
        Serial.println(firebaseData.intData());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  //}
}
