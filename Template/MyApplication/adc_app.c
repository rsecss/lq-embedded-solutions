#include "adc_app.h"

uint32_t adc_dma_buffer[2][50] = {0};
float adc_value[2] = {0.0f};

/**
 * @brief       计算 ADC 通道的平均电压值
 * 
 * @param       buffer ADC DMA缓冲区
 * @param       buffer_size 缓冲区大小
 * @return      float 计算得到的电压值(V)
 */
static float calculate_adc_voltage(uint32_t *buffer, uint8_t buffer_size)
{
    float adc_temp = 0.0f;
    
    for (uint8_t i = 0; i < buffer_size; i++)
    {
        adc_temp += (float)buffer[i];
    }
    
    return (adc_temp / buffer_size * 3.3f / 4096);
}

/**
 * @brief       ADC 转换调度函数
 * 
 * @param       无
 * @retval      无
 */
void adc_proc()
{
    adc_value[0] = calculate_adc_voltage(adc_dma_buffer[0], 50);    // R38
    adc_value[1] = calculate_adc_voltage(adc_dma_buffer[1], 50);    // R37
}
