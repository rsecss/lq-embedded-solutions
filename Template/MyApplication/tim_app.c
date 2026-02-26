#include "tim_app.h"

/**
 * @brief   设置 PWM 占空比
 * 
 * @note    此函数用于设置 TIMX 的 CHX 通道的 PWM 占空比。占空比的范围为 0%~100%
 * 
 * @param   Duty 占空比，范围为 0.0~100.0
 * @param   tim_x 定时器通道号（16 对应 htim16，17 对应 htim17）
 * @retval  无
 */
void pwm_set_duty(float duty,uint8_t tim_x)
{
    switch(tim_x)
    {
        case 16:
            TIM16->CCR1 = (TIM16->ARR + 1) * (duty / 100.0f);
            break;
        case 17:
            TIM17->CCR1 = (TIM17->ARR + 1) * (duty / 100.0f);
            break;
        default:
            break;
    }
}

/**
 * @brief   设置 PWM 频率
 * 
 * @param   frequency 目标频率（Hz）
 * @param   tim_x 定时器通道号（16 对应 htim16，17 对应 htim17）
 */
void pwm_set_frequency(int frequency, uint8_t tim_x)
{
    /* 考试可以灵活处理直接赋值 */
    // uint32_t clk = 80 * 1000 * 1000; // 80MHz
    uint32_t clk = HAL_RCC_GetPCLK2Freq();  // 获取 PCLK2 时钟频率
    if ((RCC->CFGR & RCC_CFGR_PPRE2) != RCC_CFGR_PPRE2_DIV1)
    {
        clk *= 2;
    }
    
    float duty = 0;
    uint32_t prescaler = 1;
    uint32_t arr_value = 0;
    
    /* 计算ARR和预分频器 */
    arr_value = clk / (frequency * prescaler) - 1;
    
    /* 如果 ARR 超出范围，调整预分频器 */
    if (arr_value > 65535)
    {
        prescaler = (arr_value + 65535) / 65535;
        arr_value = clk / (frequency * prescaler) - 1;
    }
    
    switch (tim_x)
    {
        case 1:
            /* 保存原占空比 */
            duty = (float)TIM16->CCR1 / (TIM16->ARR + 1);
            
            /* 设置新的预分频值和 ARR */
            __HAL_TIM_SET_PRESCALER(&htim16, prescaler - 1);
            TIM16->ARR = arr_value;
            
            /* 保持占空比不变 */
            TIM16->CCR1 = (TIM16->ARR + 1) * duty;
            
            /* 更新寄存器 */
            TIM16->EGR = TIM_EGR_UG;
            break;
        case 2:
            /* 保存原占空比 */
            duty = (float)TIM17->CCR1 / (TIM17->ARR + 1);
            
            /* 设置新的预分频值和 ARR */
            __HAL_TIM_SET_PRESCALER(&htim17, prescaler - 1);
            TIM17->ARR = arr_value;
            
            /* 保持占空比不变 */
            TIM17->CCR1 = (TIM17->ARR + 1) * duty;
            
            /* 更新寄存器 */
            TIM17->EGR = TIM_EGR_UG;
            break;
        default:
            printf("Invalid TIM number\r\n");
            break;
    }
}

#define UNIT_TIME 1000000.0f            // 单位时间 1000000us = 1s
uint32_t tim_ic_buffer[2][64] = {0};    // 定义存储输入捕获值的缓冲区
uint32_t tim_ic_val[2] = {0};           // 最终计算得到的输入捕获值
float pwm_duty = 88.8f;                 // PWM 占空比
uint32_t pwm_frequency = 9999;          // PWM 频率

/**
 * @brief   计算输入捕获值
 * 
 * @param   buffer 输入捕获 DMA 缓冲区
 * @param   buffer_size 缓冲区大小
 * @return  uint32_t 计算得到的频率值（Hz）
 */
static uint32_t calculate_ic_value(uint32_t *buffer, uint8_t buffer_size)
{
    uint32_t tim_ic_temp = 0;                // 临时存储输入捕获计算的中间值

    for (uint8_t i = 0; i < buffer_size; i++)
    {
        tim_ic_temp += buffer[i];     // 累加缓冲区中的捕获值
    }
    tim_ic_temp /= buffer_size;              // 计算平均值
    
    return (int32_t)(UNIT_TIME / (float)tim_ic_temp);
}

/**
 * @brief       TIM_IC 输入捕获处理函数  
 * 
 * @param       无
 * @retval      无
 */
void tim_proc()
{
    /* 分别计算 R39 和 R40 的输入捕获值 */
    tim_ic_val[0] = calculate_ic_value(tim_ic_buffer[0], 64); // 计算 R40 的输入捕获值
    tim_ic_val[1] = calculate_ic_value(tim_ic_buffer[1], 64); // 计算 R39 的输入捕获值

    /* 将计算得到的频率值限制在 500 到 20000 之间 */
    limit_filter(tim_ic_val, 2, 500, 20000);
 
    pwm_set_duty(pwm_duty, 16);
    pwm_set_frequency(pwm_frequency,17);
}
