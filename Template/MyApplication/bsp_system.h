#ifndef BSP_SYSTEM_H
#define BSP_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* 头文件 */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>                    // 可以不包含

/* 应用层头文件 */
#include "main.h"
#include "usart.h"
#include "rtc.h"
#include "tim.h"

#include "filter.h"
#include "scheduler.h"
#include "led_app.h"                    // led 相关的函数
#include "key_app.h"                    // 按键四行代码版本
#include "lcd.h"                        // lcd 底层驱动（官方提供）
#include "lcd_app.h"                    // lcd 相关的函数
#include "usart_app.h"                  // 串口中断 + 超时解析
#include "adc_app.h"                    // adc 相关的函数
#include "i2c_hal.h"                    // iic 相关的函数
#include "rtc_app.h"                    // rtc 相关的函数
#include "tim_app.h"                    // 定时器相关的函数

/* 全局变量，数组声明 */
extern uint8_t uart_rx_buffer[128];     // 串口接收缓存
extern uint32_t adc_dma_buffer[2][50];  // DMA 接受缓存
extern float adc_value[2];              // ADC 采样值数组
extern RTC_TimeTypeDef rtc_time;        // 定义时间结构体
extern RTC_DateTypeDef rtc_date;        // 定义日期结构体
extern uint32_t tim_ic_buffer[2][64];   // 定义存储输入捕获值的缓冲区
extern uint32_t tim_ic_val[2];          // 最终计算得到的输入捕获值
extern float pwm_duty;                  // PWM 占空比
extern uint32_t pwm_frequency;          // PWM 频率

#ifdef __cplusplus
}
#endif

#endif /* BSP_SYSTEM_H */
