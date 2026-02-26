#include "key_app.h"

static uint8_t key_val = 0;        // 当前按键状态
static uint8_t key_old = 0;        // 上一次按键状态
static uint8_t key_down = 0;       // 按键按下标志
static uint8_t key_up = 0;         // 按键松开标志

/* 底层 */
/**
 * @brief           读取按键状态
 * 
 * @param           无
 * @return          uint8_t: 返回按键编号，0 表示无按键按下，1~4 表示相应按键编号
 */
static uint8_t key_read()
{
    uint8_t temp = 0;

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET)
        temp = 1;           // 如果引脚状态为 RESET，按键一按下
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
        temp = 2;           // 如果引脚状态为 RESET，按键二按下
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == GPIO_PIN_RESET)
        temp = 3;           //如果引脚状态为 RESET，按键三按下
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
        temp = 4;           // 如果引脚状态为 RESET，按键四按下

    return temp;
}

/* 逻辑层 */
/**
 * @brief           按键控制处理函数（四行代码版本）
 * @param           无
 * @retval          无
 */
void key_proc()
{
    key_val = key_read();
    /* 计算按下的按键（当前按下状态与前一状态异或，并与当前状态相与）*/
    key_down = key_val & (key_val ^ key_old);
    /* 计算松开的按键（当前松开状态与前一状态异或，并与当前状态相与）*/
    key_up = ~key_val & (key_val ^ key_old);
    key_old = key_val;

    
}
