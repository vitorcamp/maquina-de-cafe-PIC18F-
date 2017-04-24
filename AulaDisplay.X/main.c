/* Teste */

/*
 * File:   main.c
 * Author: arlindo
 *
 * Created on April 13, 2017, 10:37 AM
 */
#include <xc.h>
#include "config.h"
#include "XLCD/xlcd.h"

#define _XTAL_FREQ 20000000

void delay(void);
void ConfigPic(void); 

//------------------------------------------------------------------------------
void DelayFor18TCY(void)
{
    for(int i=0;i<18;i++)
    __nop;
}
//------------------------------------------------------------------------------
void DelayPORXLCD(void)   // minimum 15ms
{
    __delay_ms(15);
}
//------------------------------------------------------------------------------
void DelayXLCD(void)     // minimum 5ms
{
    __delay_ms(5);
}
//------------------------------------------------------------------------------
void InitializeLCD(void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7);
    DelayPORXLCD();
    WriteCmdXLCD(DON&CURSOR_OFF&BLINK_OFF);
    DelayPORXLCD();
    while(BusyXLCD());
}
//------------------------------------------------------------------------------

void delay(void)
{
    __delay_ms(30);
    __delay_ms(30);
    __delay_ms(30);   
}

void ConfigPic(void)
{
    TRISA = 0xFF; 
    TRISB = 0xFF; 
    TRISC = 0xFF;  
    TRISE = 0xF8; 
    INTCON2bits.RBPU = 1; 
    
    PORTB = 0x00; 
}


void main(void) 
{
    int select; 
    
    // select = PORTBbits.RB1;  
    
    select = 4; 
    
    if (select == 1)
    {
   
    WriteCmdXLCD(0x01);
         
    delay();
    
    InitializeLCD();
    WriteCmdXLCD(0x80);
    putsXLCD("1.CHOCOLATE");
    WriteCmdXLCD(0xC0); 
    delay();
    putsXLCD("< ... >");
    while(1);
  
    }
    
    if (select == 2)
    {
   
    WriteCmdXLCD(0x01);
         
    delay();
    
    InitializeLCD();
    WriteCmdXLCD(0x80);
    putsXLCD("2.CHOCOLATE");
    WriteCmdXLCD(0xC0); 
    delay();
    putsXLCD("< ... >");
    while(1);
  
    }
    
    if (select == 3)
    {
   
    WriteCmdXLCD(0x01);
         
    delay();
    
    InitializeLCD();
    WriteCmdXLCD(0x80);
    putsXLCD("3.CAFE COM LEITE");
    WriteCmdXLCD(0xC0);
    delay();
    putsXLCD("< ... >");
    while(1);
  
    }
    
    if (select == 4)
    {
          
    delay();
    
    InitializeLCD();
    putsXLCD("4.CHA");
    WriteCmdXLCD(0xC1);
    putsXLCD("dkjfs");
    while(1);
  
    }
    
    
    if (select == 5)
    {
   
    WriteCmdXLCD(0x01);
         
    delay();
    
    InitializeLCD();
    WriteCmdXLCD(0x80);
    putsXLCD("5.PINGADO");
    WriteCmdXLCD(0xC0);
    delay();
    putsXLCD("< ... >");
    while(1);
  
    }
    
    
  /*  delay();
    
    InitializeLCD();
    putsXLCD("CHOCOLATE");
    WriteCmdXLCD(0xC0); 
    putsXLCD("< ... >");
    while(1); */
    
    
    return;
}
