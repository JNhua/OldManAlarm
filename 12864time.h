//***********************************************************************
//	���������
//***********************************************************************
#define LOW		0
#define HIGH    1


/*��λ��*/
#define RST_CLR	PORTE &= ~(1 << PE7)              //��ƽ�õ�
#define RST_SET	PORTE |= (1 << PE7)               //��ƽ�ø�
#define RST_IN	DDRE &= ~(1 << PE7)               //��������
#define RST_OUT	DDRE |= (1 << PE7)                //�������

/*˫������*/
#define IO_CLR	PORTE &= ~(1 << PE6)              //��ƽ�õ�
#define IO_SET	PORTE |= (1 << PE6)               //��ƽ�ø�
#define IO_R	PINE & (1 << PE6)                 //��ƽ��ȡ
#define IO_IN	DDRE &= ~(1 << PE6)               //��������
#define IO_OUT	DDRE |= (1 << PE6)                //�������
/*ʱ���ź�*/
#define SCK_CLR	PORTE &= ~(1 << PE5)              //ʱ���ź�
#define SCK_SET	PORTE |= (1 << PE5)               //��ƽ�ø�
#define SCK_IN	DDRE &= ~(1 << PE5)               //��������
#define SCK_OUT	DDRE |= (1 << PE5)                //�������

/*ds1302��������ص�ַ*/
#define ds1302_sec_add			0x80		//�����ݵ�ַ
#define ds1302_min_add			0x82		//�����ݵ�ַ
#define ds1302_hr_add			0x84		//ʱ���ݵ�ַ
#define ds1302_date_add			0x86		//�����ݵ�ַ
#define ds1302_month_add		0x88		//�����ݵ�ַ
#define ds1302_day_add			0x8a		//�������ݵ�ַ
#define ds1302_year_add			0x8c		//�����ݵ�ַ
#define ds1302_control_add		0x8e		//�������ݵ�ַ
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe

void ds1302_write_byte(unsigned char addr, unsigned char d);
unsigned char ds1302_read_byte(unsigned char addr);
void ds1302_write_time(void);
void ds1302_read_time(void);
void ds1302_init(void);
void dayToChina(unsigned char day);
void displayDateTime(void);