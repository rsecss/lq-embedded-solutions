#include "led_app.h"

static const uint8_t LED_OFF = 0x00;        // 0x00 表示全灭
static const uint8_t LED_PIN_SHIFT = 0x08;

/* 底层 */
/**
 * @brief       LED 显示函数
 * @param       led: 要控制 LED 的位置，取值范围：0x00~0xFF
 * @retval      无
 */
static void led_display(uint8_t led)
{
    /* 关闭所有的 LED */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 |
                    GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 |
                    GPIO_PIN_14 |GPIO_PIN_15, GPIO_PIN_SET);
    // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
    // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);

    /* 根据 led 的值点亮相应的灯 */
    HAL_GPIO_WritePin(GPIOC, (uint16_t)(led << LED_PIN_SHIFT), GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
}

/**
 * @brief       LED 调度函数
 * 
 * @note        这里通过位操作合并所有条件的结果，最后统一调用一次 led_display 函数，否则多次直接调用会出现 LED 状态覆盖问题，但是可以通过修改 led_display 函数的方式解决。
 * @param       无
 * @retval      无
 */
void led_proc()
{
    uint8_t led_state = LED_OFF;

    /* 根据条件判断来点亮哪一个灯 */
    
    // if (条件)
    // {
    //     led_state |= 0x01;
    // }
    // else
    // {
    //     led_state &= ~0x01;
    // }
    

    led_display(led_state);
}
