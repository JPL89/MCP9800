// @File		MCP9800.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MCP9800_H_
#define MCP9800_H_

// ADDRESS BYTE
#define MCP9800_ADDRESS_WRITE									0x90
#define MCP9800_ADDRESS_READ									0x91

// REGISTER POINTER
#define MCP9800_TEMPERATURE_REGISTER							0x00
#define MCP9800_CONFIGURATION_REGISTER							0x01
#define MCP9800_TTEMPERATURE_HYSTERESIS_REGISTER				0x02
#define MCP9800_TEMPERATURE_LIMIT_REGISTER						0x03
#define MCP9800_ONE_SHOT_ENABLE									0x80
#define MCP9800_ONE_SHOT_DISABLE								0x00
#define MCP9800_ADC_RESOLUTION_9								0x00
#define MCP9800_ADC_RESOLUTION_10								0x20
#define MCP9800_ADC_RESOLUTION_11								0x40
#define MCP9800_ADC_RESOLUTION_12								0x60
#define MCP9800_FAULT_QUEUE_0									0x00
#define MCP9800_FAULT_QUEUE_1									0x08
#define MCP9800_FAULT_QUEUE_2									0x10
#define MCP9800_FAULT_QUEUE_3									0x18
#define MCP9800_ALERT_POLARITY_HIGH								0x04
#define MCP9800_ALERT_POLARITY_LOW								0x00
#define MCP9800_COMP_INT_INTERRUPT_MODE							0x02
#define MCP9800_COMP_INT_COMPARATOR_MODE						0x00
#define MCP9800_SHUTDOWN_DISABLE								0x00
#define MCP9800_SHUTDOWN_ENABLE									0x01

void MCP9800_WriteReg(unsigned char reg, unsigned char byte)
{
	Wire_Start();
	Wire_Write(MCP9800_ADDRESS_WRITE);
	Wire_Write(reg);
	Wire_Write( byte >> 8 );
	Wire_Write( byte );
	Wire_Stop();
}

unsigned short MCP9800_ReadReg(unsigned char reg)
{
	unsigned char data = 0;
	Wire_Start();
	Wire_Write(MCP9800_ADDRESS_WRITE);
	Wire_Write(reg);
	Wire_Start();
	Wire_Write(MCP9800_ADDRESS_READ);
	data = Wire_Nack();
	Wire_Stop();
	
	return data;
}

#endif 
