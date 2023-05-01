// @File		MAIN.C		 		
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
#include "config.h"
#include "wire.h"
#include "ks0066.h"
#include "mcp9800.h"

void main(void)
{   
    PIC18F2520(); 
    
    Wire_Init();
    
    KS0066_Init();
    KS0066_Clear(0);
    KS0066_Clear(1);
    KS0066_Goto(0,0);
        
    MCP9800_WriteReg(MCP9800_CONFIGURATION_REGISTER, 0);
    
    __delay_ms(1000);
    
    int data = MCP9800_ReadReg( MCP9800_TEMPERATURE_REGISTER );
    
    KS0066_Int(data);
    
    while(1){};
    
    return;
}