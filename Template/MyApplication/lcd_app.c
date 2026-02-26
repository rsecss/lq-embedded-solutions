#include "lcd_app.h"

/* 底层 */
/**
 * @brief       在 lcd 指定行显示格式化后的字符串
 * @param       line 要显示字符串的 LCD 行号
 * @param       format 格式化字符串，后跟要格式化的参数
 * @param       ...
 * @retval      无
 * @note        该函数接受一个行号和一个格式化字符串（类似于 printf），格式化字符串后，将其显示在 LCD 的指定行上。
 * @code
 * lcd_sprintf(0, "Temperature: %d", temperature);
 * @endcode
 */
static void lcd_sprintf(uint8_t line, char *format, ...)
{
    char string[21];
    va_list arg;
    va_start(arg, format);
    vsprintf(string, format, arg);
    va_end(arg);
    LCD_DisplayStringLine(line, (u8 *)string);
}

/* 逻辑层 */
/* 自定义星期映射数组 */
static const uint8_t *weekdays[8] = {
    "ERROR",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};
/**
 * @brief       lcd 显示处理函数
 * @note        该函数用于测试 lcd 是否显示，包括显示时间、日期、ADC 值等信息。
 * @param       无
 * @retval      无
 */
void lcd_proc()
{
    static uint32_t count = 0;
    lcd_sprintf(Line0, "Count:%d", count++);
    lcd_sprintf(Line1, "ADC1:%.2f", adc_value[0]);
    lcd_sprintf(Line2, "ADC2:%.2f", adc_value[1]);
    lcd_sprintf(Line3, "IC1:%d  ", tim_ic_val[0]);
    lcd_sprintf(Line4, "IC2:%d  ", tim_ic_val[1]);
    lcd_sprintf(Line5, "DUTY:%.1f", pwm_duty);
    lcd_sprintf(Line6, "PWM:%d    ", pwm_frequency);
    lcd_sprintf(Line7, "TIME:%02d:%02d:%02d", rtc_time.Hours, rtc_time.Minutes, rtc_time.Seconds);
    lcd_sprintf(Line8, "Date:%04d-%02d-%02d", 2000 + rtc_date.Year, rtc_date.Month, rtc_date.Date);
    lcd_sprintf(Line9, "Week:%s", weekdays[rtc_date.WeekDay]);
}
