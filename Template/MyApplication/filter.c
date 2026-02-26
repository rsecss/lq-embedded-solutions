#include "filter.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief       限幅滤波算法
 * 
 * @details     限幅滤波将信号的值限制在⼀定的范围内，超出范围的部分直接裁剪
 *              常用于处理信号中的某些值由于突发的⼲扰⽽异常增⼤或减⼩
 * @param       data 数组指针
 * @param       size 数组的大小
 * @param       min_value 最小允许值
 * @param       max_value 最大允许值
 * @retval      无
 */
void limit_filter(uint32_t *data, int32_t size, uint32_t min_value, uint32_t max_value)
{
    for (int32_t i = 0; i < size; i++)
    {
        if (data[i] < min_value)
        {
            data[i] = min_value;
        }
        else if (data[i] > max_value)
        {
            data[i] = max_value;
        }
    }
}
/**
 * @brief       qsort 比较函数（升序排列）
 * 
 * @param       e1 指向第一个元素的指针
 * @param       e2 指向第二个元素的指针
 * @return      int32_t 返回值为负数表示第一个元素小于第二个元素，正数表示第一个元素大于第二个元素，0 表示相等
 */
static int32_t compare(const void *e1, const void *e2)
{
    return (*(uint32_t *)e1 - *(uint32_t *)e2);
}

/**
 * @brief       中值滤波算法
 * 
 * @details     对输入数据进行排序后取中间值作为滤波结果
 *              能有效抑制脉冲干扰和随机噪声，适合去除信号中的偶然因素引起的数据波动
 * @param       data 待滤波的数组指针
 * @param       size 数组的大小
 * @return      uint32_t 返回中值
 */
uint32_t median_filter(uint32_t *data, int size)
{
    uint32_t *temp = (uint32_t *)malloc(size * sizeof(uint32_t));   // 申请临时存储空间

    memcpy(temp, data, size * sizeof(uint32_t));
    qsort(temp, size, sizeof(uint32_t), compare);
    uint32_t median = (size % 2 == 0) ? (temp[size / 2 - 1] + temp[size / 2]) / 2 : temp[size / 2];     // 计算中值
    free(temp);                           // 释放临时存储空间

    return median;
}

/**
 * @brief       算术平均滤波
 * 
 *@details      对输入数据进行加权平均，得到一个平滑的滤波结果
 *              对信号进⾏平滑处理，减少⼩幅度的波动，如温度传感器数据的平滑
 * @param       data 待处理的数组指针。
 * @param       size 数组的大小。
 * @return      uint32_t 返回计算出的算术平均值。
 */
uint32_t average_filter(uint32_t *data, int size)
{
    uint32_t sum = 0;

    for (int32_t i = 0; i < size; i++)
    {
        sum += data[i];
    }

    return sum / size;
}

/**
 * @brief       一阶滞后滤波算法
 * 
 * @details     采用加权平均方式，当前值权重为a，前次结果权重为(1-a)
 *              适⽤于需要平滑的曲线，如慢速变化的传感器数据（如压⼒、温度）
 * @param       current_value 当前采样值
 * @return      uint32_t 滤波后的输出值
 */
uint32_t adc_filter(uint32_t current_value)
{
    static uint32_t last_value = 0;

    uint32_t temp = (32 * current_value + 96 * last_value) >> 7;
    last_value = temp;

    return last_value;
}
