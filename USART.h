//DMAVR-128的串口通信实验，通过getchar与printf输入和输出字符
//编译环境 ICCAVR 7.16A
//系统时钟7.3728MHZ，设置熔丝位为外部高频石英晶体振荡，启动时间4.1ms
//作者：阿迪 www.avrgcc.com
//日期：2010.01.14
//***********************************************************************
//			包含文件
//***********************************************************************
/*#include <stdio.h>
#include <string.h>
#include <iom128v.h>
#include <delay.h>*/


/*数码管连接情况*/
/*#define Data_IO	        PORTA                			//数码管数据口
#define Data_DDR        DDRA                 			//数据口方向寄存器
#define D_LE0	        PORTD &= ~(1 << PD4) 			//数码管段控制位为0，锁存端口数据
#define D_LE1           PORTD |= (1 << PD4)  			//数码管段控制位为1，锁存器输出与端口一致
#define W_LE0	        PORTD &= ~(1 << PD5) 			//数码管位控制位为0
#define W_LE1           PORTD |= (1 << PD5)  			//数码管位控制位为1*/

#define	F_CPU		   7372800		 						    // 单片机主频为7.3728MHz
#define baud           115200                                   //设置波特率的大小
#define baud_setting   (uint)((ulong)F_CPU/(16*(ulong)baud)-1)  //波特率计算公式
#define baud_h         (uchar)(baud_setting>>8)                 //提取高位
#define baud_l         (uchar)(baud_setting)                    //低位


void UART0_Init(void);
void puts0(void);
void uart0_rx_isr(void);
void UART1_Init(void);
void puts1(void);
void uart1_rx_isr(void);



 

