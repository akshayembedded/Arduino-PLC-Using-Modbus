#include<ModbusRtu.h>       //Library for using Modbus in Arduino
uint16_t modbus_array[3]={0,0,0};
Modbus bus(4,Serial1,6);   
void setup() {
  Serial.begin(9600);
  Serial1.begin( 19200,SERIAL_8E1 ); // baud-rate at 19200
  
  bus.start();
  //bus.setTimeOut( 10000);
  modbus_array[0]=1;
        modbus_array[1]= 100;
        modbus_array[2]= 100;
       
  // put your setup code here, to run once:

}
int a;
void loop() {
  if(Serial.available())
  {
    switch(Serial.read())
    {
      case 'a':
      modbus_array[0]=1;
        modbus_array[1]= 100;
        modbus_array[2]= 100;
        break;
        case 'b':
        modbus_array[0]=156;
        modbus_array[1]= 1103;
        modbus_array[2]= 147;
      break;
      case 'c':
       modbus_array[0]=0;
        modbus_array[1]= 1023;//Rice
        modbus_array[2]= 0;//kerosene
        break;
        case 'd':
          modbus_array[0]=0;
        modbus_array[1]= 0;//Rice
        modbus_array[2]= 1023;
          bus.poll(modbus_array,3);
          break;
          case 'e':
               modbus_array[0]=0;
        modbus_array[1]= 1023;//Rice
        modbus_array[2]= 1023;
        break;
    }
    do
    {
    a=(bus.poll(modbus_array,3));
    }while(a!=11);
    Serial.print(modbus_array[0]);
    Serial.print(" ");
     Serial.print(modbus_array[1]);
    Serial.print(" ");
   Serial.print(modbus_array[2]);
    Serial.println(" ");
  }// put your main code here, to run repeatedly:

}
