#include <string.h>
#include <stdio.h>
#include <iom128v.h>
#include "USART.h"
#include "basic.h"
#include "ESP8266.h"

//�����ַ�����
extern uchar TxCharBuf_wifi[128];
extern uchar TxStrLen_wifi;
//�����ַ�����
extern uchar RxCharBuf_wifi[16];
extern uchar RxCharNum_wifi, RxBufWr_wifi, RxBufRd_wifi;

//***********************************************************************
//	wifiģ������
//***********************************************************************
void wifi_Restart(void)
{
    sprintf(TxCharBuf_wifi, "AT+RST");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	wifiģ������wifi�ȵ�
//***********************************************************************
void wifi_ConnectSTA(void)
{
    sprintf(TxCharBuf_wifi, "AT+CWJAP=ICHARM,meiyanliang");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	����Ϊ��·����ģʽ
//***********************************************************************
void wifi_CIPMUX(void)
{
    sprintf(TxCharBuf_wifi, "AT+CIPMUX=0");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	����TCP����
//***********************************************************************
void wifi_TCPConnect(void)
{
    sprintf(TxCharBuf_wifi, "TCP,alarm.icharm.me,80");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	����ģ��Ϊ͸��ģʽ
//***********************************************************************
void wifi_CIPMODE(void)
{
    sprintf(TxCharBuf_wifi, "AT+CIPMODE=1");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	ʹ��͸��ģʽ���������������
//***********************************************************************
void wifi_CIPSEND(void)
{
    sprintf(TxCharBuf_wifi, "AT+CIPSEND");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}


//***********************************************************************
//	���Ͷ���
//***********************************************************************
void wifi_SendMsg(void)
{
    sprintf(TxCharBuf_wifi, "GET http://alarm.icharm.me");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	���Ͷ���
//***********************************************************************
void wifi_SENDMSG(void)
{
    wifi_TCPConnect();
    delay_nms(200);
    wifi_CIPMODE();
    delay_nms(200);
    wifi_CIPSEND();
    delay_nms(50);
    wifi_SendMsg();
}
