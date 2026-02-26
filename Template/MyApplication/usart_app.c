#include "usart_app.h"

uint16_t uart_rx_index = 0;
uint32_t uart_rx_ticks = 0;
uint8_t uart_rx_buffer[128] = {0};

/**
 * @brief       中断回调函数
 * 
 * @param       huart1 uart1句柄
 * @retval      无 
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        uart_rx_ticks = HAL_GetTick();      // 记录接收到数据的时间
        uart_rx_index++;                    // 指针往下偏移
        HAL_UART_Receive_IT(&huart1, &uart_rx_buffer[uart_rx_index], 1);    // 使能接收中断
    }
}

/**
 * @brief       处理 USART 接收缓冲区中的数据
 * 
 * @note        如果在 100ms 内没有接收到新的数据，将清空缓冲区
 * @param       无
 * @retval      无
 */
void uart_proc()
{
    if (uart_rx_index == 0)
        return;   // 如果接收索引为 0，说明没有数据需要处理，直接返回
    if (HAL_GetTick() - uart_rx_ticks > 100)
    {
        // printf("uart data: %s\n", uart_rx_buffer);
        memset(uart_rx_buffer, 0, uart_rx_index);   // 清空缓冲区
        uart_rx_index = 0;                          // 重置索引
        huart1.pRxBuffPtr = uart_rx_buffer;         // 将缓存区指针重置成初始位置
    }
}
