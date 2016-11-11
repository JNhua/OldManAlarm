#include "basic.h"

//***********************************************************************
//	���������
//***********************************************************************
#define RS_CLR	PORTF &= ~(1 << PF1)                 //RS�õ�
#define RS_SET	PORTF |= (1 << PF1)                  //RS�ø�

#define RW_CLR	PORTF &= ~(1 << PF2)                 //RW�õ�
#define RW_SET	PORTF |= (1 << PF2)                  //RW�ø�

#define EN_CLR	PORTF &= ~(1 << PF3)                 //E�õ�
#define EN_SET	PORTF |= (1 << PF3)                  //E�ø�

#define PSB_CLR	PORTF &= ~(1 << PE2)                 //PSB�õͣ����ڷ�ʽ
#define PSB_SET	PORTF |= (1 << PE2)                  //PSB�øߣ����ڷ�ʽ

#define LOW		0
#define HIGH    1

//��ʼ��ָ��
#define CLEAR_SCREEN	0x01		//����ָ�������ACֵΪ00H
#define AC_INIT		    0x02		//��AC����Ϊ00H�����α��Ƶ�ԭ��λ��
#define CURSE_ADD		0x06		//�趨�α��Ƶ�����ͼ�������ƶ�����Ĭ���α����ƣ�ͼ�����岻����
#define FUN_MODE		0x30		//����ģʽ��8λ����ָ�
#define DISPLAY_ON		0x0c		//��ʾ��,��ʾ�α꣬���α�λ�÷���
#define DISPLAY_OFF		0x08		//��ʾ��
#define CURSE_DIR		0x14		//�α������ƶ�:AC=AC+1
#define SET_CG_AC		0x40		//����AC����ΧΪ��00H~3FH
#define SET_DD_AC		0x80

#define Data_IO	        PORTA                //Һ�����ݿ�
#define Data_DDR        DDRA                 //���ݿڷ���Ĵ���
#define D_LE0	        PORTD &= ~(1 << PD4) //����ܶο���λΪ0������˿�����
#define D_LE1           PORTD |= (1 << PD4)  //����ܶο���λΪ1�������������˿�һ��
#define W_LE0	        PORTD &= ~(1 << PD5) //�����λ����λΪ0
#define W_LE1           PORTD |= (1 << PD5)  //�����λ����λΪ1

void system_init(void);
void LCD_write_com(unsigned char com);
void LCD_write_data(unsigned char data);
void LCD_write_char(unsigned char x,unsigned char y,unsigned char data) ;
void LCD_clear(void);
void DisplayCgrom(uchar addr,uchar *hz);
void LCD_init(void);