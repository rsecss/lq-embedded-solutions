#include "scheduler.h"

uint8_t task_number = 0;        // 全局变量，用于存储用户任务数量

typedef struct {
    void (*task_func)(void);    // 任务函数
    uint32_t period_ms;         // 任务执行周期（ms）
    uint32_t last_run_time;     // 上次执行时间（ms）
}task_t;

/* 静态调度器任务列表，每个任务包括任务函数、执行周期（ms）、上次执行时间（ms） */
static task_t scheduler_task[] = {
    {led_proc, 10, 0},      // LED 任务，周期为 10ms，初始上次运行时间为 0
    {key_proc, 10, 0},      // KEY 任务，周期为 50ms，初始上次运行时间为 0
    {lcd_proc, 100, 0},     // LCD 任务，周期为 100ms，初始上次运行时间为 0
    {uart_proc, 10, 0},     // UART 任务，周期为 10ms，初始上次运行时间为 0
    {adc_proc, 20, 0},      // ADC 任务，周期为 20ms，初始上次运行时间为 0
    {rtc_proc, 10, 0},      // RTC 任务，周期为 10ms，初始上次运行时间为 0
    {tim_proc, 50, 0},   // TIM_IC 任务，周期为 100ms，初始上次运行时间为 0
};

/**
 * @brief       调度器初始化函数
 * 
 * @param       无
 * @retval      无
 */
void scheduler_init()
{
    task_number = sizeof(scheduler_task) / sizeof(task_t);
}

/**
 * @brief       调度器运行函数
 * @param       无
 * @retval      无
 */
void scheduler_run()
{
    for (uint8_t i = 0; i < task_number; i++)
    {
        uint32_t now_time = HAL_GetTick();

        if (now_time >= scheduler_task[i].last_run_time + scheduler_task[i].period_ms)
        {
            scheduler_task[i].last_run_time = now_time;     // 更新任务的上次运行时间为当前时间
            scheduler_task[i].task_func();                  // 执行任务函数
        }
    }
}
