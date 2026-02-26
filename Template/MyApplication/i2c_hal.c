/*
  程序说明: CT117E-M4嵌入式竞赛板GPIO模拟I2C总线驱动程序
  软件环境: MDK-ARM HAL库
  硬件环境: CT117E-M4嵌入式竞赛板
  日    期: 2020-3-1
*/

#include "i2c_hal.h"

#define DELAY_TIME	20

/**
  * @brief SDA线输入模式配置
  * @param None
  * @retval None
  */
void SDA_Input_Mode()
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.Pin = GPIO_PIN_7;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/**
  * @brief SDA线输出模式配置
  * @param None
  * @retval None
  */
void SDA_Output_Mode()
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.Pin = GPIO_PIN_7;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/**
  * @brief SDA线输出一个位
  * @param val 输出的数据
  * @retval None
  */
void SDA_Output( uint16_t val )
{
    if ( val )
    {
        GPIOB->BSRR |= GPIO_PIN_7;
    }
    else
    {
        GPIOB->BRR |= GPIO_PIN_7;
    }
}

/**
  * @brief SCL线输出一个位
  * @param val 输出的数据
  * @retval None
  */
void SCL_Output( uint16_t val )
{
    if ( val )
    {
        GPIOB->BSRR |= GPIO_PIN_6;
    }
    else
    {
        GPIOB->BRR |= GPIO_PIN_6;
    }
}

/**
  * @brief SDA输入一位
  * @param None
  * @retval GPIO读入一位
  */
uint8_t SDA_Input(void)
{
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_SET){
		return 1;
	}else{
		return 0;
	}
}


/**
  * @brief I2C的短暂延时
  * @param None
  * @retval None
  */
static void delay1(unsigned int n)
{
    uint32_t i;
    for ( i = 0; i < n; ++i);
}

/**
  * @brief I2C起始信号
  * @param None
  * @retval None
  */
void I2CStart(void)
{
    SDA_Output(1);
    delay1(DELAY_TIME);
    SCL_Output(1);
    delay1(DELAY_TIME);
    SDA_Output(0);
    delay1(DELAY_TIME);
    SCL_Output(0);
    delay1(DELAY_TIME);
}

/**
  * @brief I2C结束信号
  * @param None
  * @retval None
  */
void I2CStop(void)
{
    SCL_Output(0);
    delay1(DELAY_TIME);
    SDA_Output(0);
    delay1(DELAY_TIME);
    SCL_Output(1);
    delay1(DELAY_TIME);
    SDA_Output(1);
    delay1(DELAY_TIME);

}

/**
  * @brief I2C等待确认信号
  * @param None
  * @retval None
  */
unsigned char I2CWaitAck(void)
{
    unsigned short cErrTime = 5;
    SDA_Input_Mode();
    delay1(DELAY_TIME);
    SCL_Output(1);
    delay1(DELAY_TIME);
    while(SDA_Input())
    {
        cErrTime--;
        delay1(DELAY_TIME);
        if (0 == cErrTime)
        {
            SDA_Output_Mode();
            I2CStop();
            return ERROR;
        }
    }
    SDA_Output_Mode();
    SCL_Output(0);
    delay1(DELAY_TIME);
    return SUCCESS;
}

/**
  * @brief I2C发送确认信号
  * @param None
  * @retval None
  */
void I2CSendAck(void)
{
    SDA_Output(0);
    delay1(DELAY_TIME);
    delay1(DELAY_TIME);
    SCL_Output(1);
    delay1(DELAY_TIME);
    SCL_Output(0);
    delay1(DELAY_TIME);

}

/**
  * @brief I2C发送非确认信号
  * @param None
  * @retval None
  */
void I2CSendNotAck(void)
{
    SDA_Output(1);
    delay1(DELAY_TIME);
    delay1(DELAY_TIME);
    SCL_Output(1);
    delay1(DELAY_TIME);
    SCL_Output(0);
    delay1(DELAY_TIME);

}

/**
  * @brief I2C发送一个字节
  * @param cSendByte 需要发送的字节
  * @retval None
  */
void I2CSendByte(unsigned char cSendByte)
{
    unsigned char  i = 8;
    while (i--)
    {
        SCL_Output(0);
        delay1(DELAY_TIME);
        SDA_Output(cSendByte & 0x80);
        delay1(DELAY_TIME);
        cSendByte += cSendByte;
        delay1(DELAY_TIME);
        SCL_Output(1);
        delay1(DELAY_TIME);
    }
    SCL_Output(0);
    delay1(DELAY_TIME);
}

/**
  * @brief I2C接收一个字节
  * @param None
  * @retval 接收到的字节
  */
unsigned char I2CReceiveByte(void)
{
    unsigned char i = 8;
    unsigned char cR_Byte = 0;
    SDA_Input_Mode();
    while (i--)
    {
        cR_Byte += cR_Byte;
        SCL_Output(0);
        delay1(DELAY_TIME);
        delay1(DELAY_TIME);
        SCL_Output(1);
        delay1(DELAY_TIME);
        cR_Byte |=  SDA_Input();
    }
    SCL_Output(0);
    delay1(DELAY_TIME);
    SDA_Output_Mode();
    return cR_Byte;
}

//
void I2CInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.Pin = GPIO_PIN_7 | GPIO_PIN_6;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void I2CStart(void);
void I2CStop(void);
unsigned char I2CWaitAck(void);
void I2CSendAck(void);
void I2CSendNotAck(void);
void I2CSendByte(unsigned char cSendByte);
unsigned char I2CReceiveByte(void);
void I2CInit(void);

/**
 * @brief     向 EEPROM 写入数据
 * 
 * @param     eeprom_string 指向要写入 EEPROM 的数据的指针
 * @param     address EEPROM 内存中的起始地址
 * @param     number 要写入的数据字节数
 * @retval    无
 */
void eeprom_wirte(uint8_t *eeprom_string, uint8_t address, uint8_t number)
{
  I2CStart();                     // 发送起始信号
  I2CSendByte(0xA0);              // 发送 EEPROM 写命令（器件地址 + 写操作位）
  I2CWaitAck();                   // 等待 EEPROM 的 ACK 信号

  I2CSendByte(address);           // 发送要写入 EEPROM 内存起始地址
  I2CWaitAck();                   // 等待 EEPROM 的 ACK 信号

  /* 逐字节写入 EEPROM */
  while (number--) {
    I2CSendByte(*eeprom_string++);    // 发送当前字节的数据
    I2CWaitAck();                     // 等待 EEPROM 的 ACK 信号
    delay1(200);                      // 延时确保数据写入
  }

  I2CStop();                     // 发送停止信号
  HAL_Delay(5);                  // 连续写入需要延时确保数据写入
}

/**
 * @brief     从 EEPROM 读取数据
 * 
 * @param     eeprom_string 指向存储读取数据的缓冲区的指针
 * @param     address EEPROM 内存中的起始地址
 * @param     number 要读取的数据字节数
 * @retval    无
 */
void eeprom_read(uint8_t *eeprom_string, uint8_t address, uint8_t number)
{
  I2CStart();                     // 启动 I2C 通信
  I2CSendByte(0xA0);              // 发送 EEPROM 写命令（器件地址 + 写操作位）
  I2CWaitAck();                   // 等待 EEPROM 的 ACK 信号

  I2CSendByte(address);           // 发送要读取 EEPROM 内存起始地址
  I2CWaitAck();                   // 等待 EEPROM 的 ACK 信号

  I2CStart();                     // 再次启动 I2C 通信，准备读操作
  I2CSendByte(0xA1);              // 发送 EEPROM 读命令（器件地址 + 读操作位）
  I2CWaitAck();                   // 等待 EEPROM 的 ACK 信号

  while (number--) {
    *eeprom_string++ = I2CReceiveByte();    // 读取当前字节的数据
    if (number) {
      I2CSendAck();                         // 如果还需要继续读取,发送 ACK 信号
    } else {
      I2CSendNotAck();                      // 如果不需要继续读取,发送 NACK 信号
    }
  }

  I2CStop();                     // 停止 I2C 通信
}

/**
 * @brief     向 MCP4017 写入数据
 * 
 * @param     data 要写入 MCP4017 的数据
 * @retval    无
 */
void mcp4017_write(uint8_t data)
{
  I2CStart();             // 启动 I2C 通信
  I2CSendByte(0x5E);      // 发送 MCP4017 写命令（器件地址 + 写操作位）
  I2CWaitAck();           // 等待 MCP4017 的 ACK 信号
  I2CSendByte(data);      // 发送要写入 MCP4017 的数据
  I2CWaitAck();           // 等待 MCP4017 的 ACK 信号
  I2CStop();              // 停止 I2C 通信
}

/**
 * @brief     从 MCP4017 读取数据
 * 
 * @param     data 指向存储读取数据的变量的指针
 * @retval    无
 */
void mcp4017_read(uint8_t *data)
{
  I2CStart();                 // 启动 I2C 通信
  I2CSendByte(0x5F);          // 发送 MCP4017 读命令（器件地址 + 读操作位）
  I2CWaitAck();               // 等待 MCP4017 的 ACK 信号
  *data = I2CReceiveByte();   // 读取当前字节的数据
  I2CSendNotAck();            // 发送 NACK 信号
  I2CStop();                  // 停止 I2C 通信
}
