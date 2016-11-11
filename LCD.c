#include <iom128v.h>
#include "LCD.h"
#include "basic.h"

//*************************************************************************
//			��ʼ���ӳ���
//*************************************************************************
void system_init(void){

	Data_IO = 0xFF;				        //��ƽ����
	Data_DDR = 0xFF;				        //�������

	PORTF = 0xFF;                       //��ƽ����
	DDRF = 0xFF;                        //�������
    PORTD=0xFF;
	DDRD=0xFF;
	PORTE=0xFF;                        //PSB��Ӧ��PE2
	DDRE=0xfe;
	D_LE1;                             //�ص�����ܣ�������ʾ����                   
    W_LE1;                     
    Data_IO=0xFF;                      //�������            
    W_LE0; 
	
	PORTB=0xFF;				  		   //�رշ��������
	DDRB=0xFF;

	PSB_SET;						   //Һ�����ڷ�ʽ
}


//***********************************************************************
//	��ʾ������д�뺯��
//***********************************************************************


void LCD_write_com(unsigned char com) 
{	
	RS_CLR;
	RW_CLR;
	EN_SET;
	Data_IO = com;
	delay_nms(5);
	EN_CLR;
}

//***********************************************************************
//	��ʾ������д�뺯��
//***********************************************************************

void LCD_write_data(unsigned char data) 
{
    RS_SET;
	RW_CLR;
	EN_SET;
	Data_IO = data;
	delay_nms(5);
	EN_CLR;
}

//***********************************************************************
//	��ʾ�����ַ�д�뺯��
//***********************************************************************

void LCD_write_char(unsigned char x,unsigned char y,unsigned char data) 
{
	
    if (y == 0) 
    {
    	LCD_write_com(0x80 + x);
    }
    else 
    {
    	LCD_write_com(0x90 + x);
    }
    delay_nms(2);
    LCD_write_data( data);  
}

//***********************************************************************
//	��ʾ�������ʾ
//***********************************************************************

void LCD_clear(void) 
{
	LCD_write_com(0x01);
	delay_nms(10);
}

//***********************************************************************
//�������ƣ�DisplayCgrom(uchar hz)��ʾCGROM��ĺ���
//***********************************************************************
void DisplayCgrom(uchar addr,uchar *hz)
{
	LCD_write_com(addr);
    delay_nms(5);
	while(*hz != '\0')
	{
		LCD_write_data(*hz);
		hz++;
        delay_nms(5);
	}

}

//***********************************************************************
//	��ʾ����ʼ������
//***********************************************************************

void LCD_init(void) 
{
	DDRA = 0xFF;				        //I/O�ڷ�������
	DDRA |= (1 << PA5) | (1 << PA6) | (1 << PA7);
	LCD_write_com(FUN_MODE);			//��ʾģʽ����
	delay_nms(5);
	LCD_write_com(FUN_MODE);			//��ʾģʽ����
	delay_nms(5);
    LCD_write_com(DISPLAY_ON);			//��ʾ��
	delay_nms(5);
    LCD_write_com(CLEAR_SCREEN);			//����
	delay_nms(5);
}