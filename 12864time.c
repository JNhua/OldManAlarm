//DMAVR-128������12864��Һ����ʾʵʱʱ����������
//���뻷�� ���뻷�� ICCAVR 7.16A
//ϵͳʱ��7.3728MHZ��������˿λΪ�ⲿ��ƵʯӢ�����񵴣�����ʱ��4.1ms
//���ߣ����� www.avrgcc.com
//���ڣ�2010.12.112

//***********************************************************************
//			�����ļ�
//***********************************************************************



#include <iom128v.h>
#include "12864time.h"
#include "basic.h"
#include "LCD.h"

volatile unsigned char time_buf[8] = {0x20,0x14,0x10,0x14,0x22,0x54,0x59,0x05};

//***********************************************************************
//��DS1302д��һ�ֽ�����
//***********************************************************************
void ds1302_write_byte(unsigned char addr, unsigned char d) 
{

	unsigned char i;
	RST_SET;					//����DS1302����
	
	                                                //д��Ŀ���ַ��addr
	IO_OUT;
	addr = addr & 0xFE;                            //���λ����
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;
		SCK_CLR;
		addr = addr >> 1;
		}
	
	                                              //д�����ݣ�d
	IO_OUT;
	for (i = 0; i < 8; i ++) {
		if (d & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;
		SCK_CLR;
		d = d >> 1;
		}
	RST_CLR;					//ֹͣDS1302����
}

//***********************************************************************
//                   ��DS1302����һ�ֽ�����
//***********************************************************************
unsigned char ds1302_read_byte(unsigned char addr)
 {

	unsigned char i;
	unsigned char temp;
	RST_SET;					//����DS1302����

	                                                //д��Ŀ���ַ��addr
	IO_OUT;
	addr = addr | 0x01;                             //���λ�ø�
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;
		SCK_CLR;
		addr = addr >> 1;
		}
	
	/*������ݣ�temp*/
	IO_IN;
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (IO_R) {
			temp |= 0x80;
			}
		else {
			temp &= 0x7F;
			}
		SCK_SET;
		SCK_CLR;
		}
	
	RST_CLR;					//ֹͣDS1302����
	return temp;
}

//***********************************************************************
//                   ��DS302д��ʱ������
//***********************************************************************

void ds1302_write_time(void)
 {

	ds1302_write_byte(ds1302_control_add,0x00);		//�ر�д���� 
	ds1302_write_byte(ds1302_sec_add,0x80);			//��ͣ 
	//ds1302_write_byte(ds1302_charger_add,0xa9);		//������ 
	ds1302_write_byte(ds1302_year_add,time_buf[1]);		//�� 
	ds1302_write_byte(ds1302_month_add,time_buf[2]);	//�� 
	ds1302_write_byte(ds1302_date_add,time_buf[3]);		//�� 
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		//�� 
	ds1302_write_byte(ds1302_hr_add,time_buf[4]);		//ʱ 
	ds1302_write_byte(ds1302_min_add,time_buf[5]);		//��
	ds1302_write_byte(ds1302_sec_add,time_buf[6]);		//��
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		//�� 
	ds1302_write_byte(ds1302_control_add,0x80);		//��д���� 
}

//***********************************************************************
//                     ��DS302����ʱ������
//***********************************************************************

void ds1302_read_time(void)  
{ 

	time_buf[1]=ds1302_read_byte(ds1302_year_add);		//�� 
	time_buf[2]=ds1302_read_byte(ds1302_month_add);		//�� 
	time_buf[3]=ds1302_read_byte(ds1302_date_add);		//�� 
	time_buf[4]=ds1302_read_byte(ds1302_hr_add);		//ʱ 
	time_buf[5]=ds1302_read_byte(ds1302_min_add);		//�� 
	time_buf[6]=(ds1302_read_byte(ds1302_sec_add))&0x7F;//�� 
	time_buf[7]=ds1302_read_byte(ds1302_day_add);		//�� 
}

//***********************************************************************
//               DS302��ʼ������
//***********************************************************************

void ds1302_init(void) 
{
	
	RST_CLR;			//RST���õ�
	SCK_CLR;			//SCK���õ�
	RST_OUT;			//RST������Ϊ���
	SCK_OUT;			//SCK������Ϊ���
}



//***********************************************************************
//	������ת������
//***********************************************************************
void dayToChina(unsigned char day)
{
 	    if(day == 0x01)
	 		DisplayCgrom(0x86,"��һ");
		if(day == 0x02)
	 		DisplayCgrom(0x86,"�ܶ�");
		if(day == 0x03)
	 		DisplayCgrom(0x86,"����");
		if(day == 0x04)
	 		DisplayCgrom(0x86,"����");
		if(day == 0x05)
	 		DisplayCgrom(0x86,"����");
		if(day == 0x06)
	 		DisplayCgrom(0x86,"����");
		if(day == 0x07)
	 		DisplayCgrom(0x86,"����");
}

//***********************************************************************
//	��ʾϵͳʱ�� �����ա�����
//***********************************************************************
void displayDateTime(void)
{
 	volatile unsigned char temp;
    delay_nms(200);
	ds1302_read_time();                		  //��DS1302����
		
	LCD_write_com(0x80);
	delay_nms(2);
    temp = (time_buf[0] >> 4) + '0';          //��LCD��дҪ��ʾ������	
    LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[0] & 0x0F) + '0';	
	LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[1] >> 4) + '0';		
    LCD_write_data(temp);
	delay_nms(2);
		 
	temp = (time_buf[1] & 0x0F) + '0';
	LCD_write_data(temp);
	delay_nms(2);
	LCD_write_data('-');
	delay_nms(2);

	temp = (time_buf[2] >> 4) + '0';		
    LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[2] & 0x0F) + '0';
	LCD_write_data(temp);
	delay_nms(2);
	LCD_write_data('-');
	delay_nms(2);

	temp = (time_buf[3] >> 4) + '0';		
    LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[3] & 0x0F) + '0';
	LCD_write_data(temp);
	delay_nms(2);
		
	//��ʾ����
	dayToChina(time_buf[7]);
	delay_nms(2);
		

	LCD_write_com(0x90);
	delay_nms(5);

	temp = (time_buf[4] >> 4) + '0';		
    LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[4] & 0x0F) + '0';
	LCD_write_data(temp);
	delay_nms(2);
	LCD_write_data(':');
	delay_nms(2);

	temp = (time_buf[5] >> 4) + '0';		
    LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[5] & 0x0F) + '0';
	LCD_write_data(temp);
	delay_nms(2);
	LCD_write_data(':');
	delay_nms(2);

	temp = (time_buf[6] >> 4) + '0';		
    LCD_write_data(temp);
	delay_nms(2);
	temp = (time_buf[6] & 0x0F) + '0';
	LCD_write_data(temp);
	delay_nms(2);
}