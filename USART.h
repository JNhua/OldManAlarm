//DMAVR-128�Ĵ���ͨ��ʵ�飬ͨ��getchar��printf���������ַ�
//���뻷�� ICCAVR 7.16A
//ϵͳʱ��7.3728MHZ��������˿λΪ�ⲿ��ƵʯӢ�����񵴣�����ʱ��4.1ms
//���ߣ����� www.avrgcc.com
//���ڣ�2010.01.14
//***********************************************************************
//			�����ļ�
//***********************************************************************
/*#include <stdio.h>
#include <string.h>
#include <iom128v.h>
#include <delay.h>*/


/*������������*/
/*#define Data_IO	        PORTA                			//��������ݿ�
#define Data_DDR        DDRA                 			//���ݿڷ���Ĵ���
#define D_LE0	        PORTD &= ~(1 << PD4) 			//����ܶο���λΪ0������˿�����
#define D_LE1           PORTD |= (1 << PD4)  			//����ܶο���λΪ1�������������˿�һ��
#define W_LE0	        PORTD &= ~(1 << PD5) 			//�����λ����λΪ0
#define W_LE1           PORTD |= (1 << PD5)  			//�����λ����λΪ1*/

#define	F_CPU		   7372800		 						    // ��Ƭ����ƵΪ7.3728MHz
#define baud           115200                                   //���ò����ʵĴ�С
#define baud_setting   (uint)((ulong)F_CPU/(16*(ulong)baud)-1)  //�����ʼ��㹫ʽ
#define baud_h         (uchar)(baud_setting>>8)                 //��ȡ��λ
#define baud_l         (uchar)(baud_setting)                    //��λ


void UART0_Init(void);
void puts0(void);
void uart0_rx_isr(void);
void UART1_Init(void);
void puts1(void);
void uart1_rx_isr(void);



 
