/*
 * Select_sensors.c
 *
 *  Created on: Mar 4, 2024
 *      Author: Administrator
 */

#include "stm32wlxx_hal.h"
#include "sys_app.h"
#include "Sensors.h"
#include "stdlib.h"
#include<stdio.h>

/***************   BME280_VARAIBLES__***************/
float Temp, Press, Hum;

/***************   DHT11_VARAIBLES__***************/
uint8_t  Dht_Rh_byte1,  Dht_Rh_byte2,  Dht_Temp_byte1,  Dht_Temp_byte2;
uint16_t SUM, DHT_RH, DHT_TEMP;

uint8_t Tmsg[7],Hmsg[7];

float DHT_Temperature = 0;
float DHT_Humidity = 0;
uint8_t Presence = 0;

extern uint16_t mode;

void Get_sensor_value(SensorDataTypedef *SensorData,uint16_t value)
{
	switch(value)
	 {
	     case ACTIVATE_BME:
		 uint8_t temp_val[7], press_val[7], Hum_val[7] ;
		 BME280_Measure();
		 SensorData->Sens_Temperature=Temp*100;
		 SensorData->Sens_Humidity = Hum *100;
		 SensorData->Sens_Pressure = (Press / 1000) *100;//pressure in pascal converted to kilo pascal
		 gcvt(Temp,7,temp_val);
		 APP_LOG(TS_ON, VLEVEL_L, "BME280 sens_Temp  : ~%s\n\r",temp_val);
		 gcvt(Press,7,press_val);
		 APP_LOG(TS_ON, VLEVEL_L, "BME280 sens_Press  : ~%s\n\r",press_val );
		 gcvt(Hum,7,Hum_val);
		 APP_LOG(TS_ON, VLEVEL_L, "BME280 sens_Hum  : ~%s\n\r",Hum_val );

		 break;


	 case ACTIVATE_DS18B20 :
	 		SensorData->Sens_Humidity=65535;
	 		SensorData->Sens_Pressure=65535;
	 		SensorData->Sens_Temperature =DS18B20_Get_Value();
	 	  break;

	 case ACTIVATE_DHT11 :
	                 DHT11_Start();
	                 Presence = DHT11_Check_Response();
	                 Dht_Rh_byte1 = DHT11_Read ();
	                 Dht_Rh_byte2 = DHT11_Read ();
	                 Dht_Temp_byte1 = DHT11_Read ();
	                 Dht_Temp_byte2 = DHT11_Read ();
	                 SUM = DHT11_Read();

	                 DHT_TEMP = Dht_Temp_byte1;
	                 DHT_RH = Dht_Rh_byte1;

	                 DHT_Temperature = (float) DHT_TEMP;
	                 DHT_Humidity = (float) DHT_RH;

	                 gcvt(DHT_Humidity,7,Hmsg);
	                 APP_LOG(TS_ON, VLEVEL_M, "DHT11 Humidity : %s\n\r",Hmsg);
	                 gcvt(DHT_Temperature,7,Tmsg);
	                 APP_LOG(TS_ON, VLEVEL_M, "DHT11 Temperature  : %s\n\r",Tmsg);
	                 SensorData->Sens_Temperature = DHT_Temperature * 100;
	                 SensorData->Sens_Humidity = DHT_Humidity * 100;
	            break;

	 case ACTIVATE_MQ6:
	 		 mode=0;
	          uint16_t MQ6_value = MQ6_sensor();
	          APP_LOG(TS_OFF, VLEVEL_L, "MQ6 sensor_in PPM = %d\n\r", MQ6_value);
	         break;
	 }
}
