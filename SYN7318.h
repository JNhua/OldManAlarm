#include "basic.h"

/*命令字*/
#define PLAY_TEXT 0x01         //播放发送的文本
#define SET_VOLUME 0x05        //设置播放音量
#define START_RECOGN 0x10      //开始语音识别
#define STOP_RECOGN 0x11       //停止语音识别
#define SET_PARAM 0x1E         //设置语音识别参数
#define UPADTE_WORD 0x1F       //更新识别词条
#define ON_AWAKEN 0x51         //开启语音唤醒功能
#define OFF_AWAKEN 0x52        //关闭语音唤醒
#define SET_AWKEN_WORD 0x53    //设置自定义唤醒名
#define CHECK_STATUS 0x21      //查询当前模块的工作状态

/*回传命令字 通用*/
#define INIT_OK 0x4A           //模块初始化成功回传
#define ACC_OK  0x41           //接收成功，命令帧正确
#define ACC_ERR 0x45           //接收失败，收到不能识别的命令帧

/*回传命令字 状态查询*/
#define STA_RECOGN 0x42        //模块处于语音识别或语音唤醒状态
#define STA_PLA_MP3 0x49       //正在播放mp3
#define STA_UPD_WORD 0x4B      //正在更新词典
#define STA_PLA_TEXT 0x4E      //正在播放合成的文本
#define STA_FREE 0x4F          //空闲状态

/*回传命令字 开始语音唤醒*/
#define AWKEN_OK 0x21          //语音唤醒成功
#define AWKEN_ERR 0x22         //唤醒内部错误

/*回传命令字 设置自定义唤醒名*/
#define SET_AWK_OK 0x23        //自定义唤醒名设置成功
#define SET_AWK_ERR 0x24       //自定义唤醒名设置成功

/*回传命令字 词条更新*/
#define UPD_OK  0x31           //词典更新成功
#define UPD_ERR  0x32           //词典更新失败

/*回传命令字 语音识别*/
#define RECON_OK 0x01           //识别成功（带命令ID号）
#define OVER_TIME 0x03          //用户静音超时
#define SPK_TIME 0x04           //用户语音超时
#define RECO_REJECT   0x07      //识别被拒
#define INN_ERROR 0x06              //内部错误

/*命令参数*/
#define GB2312 0x00            //GB2312编码
#define DIS_NEAR 0x02          //识别距离为中
#define QUI_H 0x0B             //用户静音上限高字节
#define QUI_L 0xB8             //用户静音上限低字节 3000ms
#define RECO_TIME_H 0x13       //用户语音上限高字节
#define RECO_TIME_L 0x88       //用户语音上限低字节 5000ms
#define REFUSE_LEVEL 0x04      //拒识级别 较低


/*复位脚 PC7*/
#define RST_SYN_CLR	PORTC &= ~(1 << PC7)              //电平置低
#define RST_SYN_SET	PORTC |= (1 << PC7)               //电平置高
#define RST_SYN_IN	DDRC &= ~(1 << PC7)               //方向输入
#define RST_SYN_OUT	DDRC |= (1 << PC7)                //方向输出
/*开关脚 PC6*/
#define SRT_SYN_CLR	PORTC &= ~(1 << PC6)              //电平置低
#define SRT_SYN_SET	PORTC |= (1 << PC6)               //电平置高
#define SRT_SYN_IN	DDRC &= ~(1 << PC6)               //方向输入
#define SRT_SYN_OUT	DDRC |= (1 << PC6)                //方向输出

void SYN7318_init(void);
//void buildHead(uchar low, uchar command);
void voicePlayer(uchar *content);
void SYN7318_welcome(void);
void SYN7318_Error(void);
uint checkSendReturn(void);
void setVoiceLevel(uchar level);
void setVoiceOption(void);
void updateWords(void);
void waitFree(void);
void startRecognition(void);