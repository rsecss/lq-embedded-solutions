由于从第十五届开始就全部使用的新的开发板，然后本届国赛题目上的有些功能需要拓展版实现，所以这里就用其他方式代替实现：
1. 测量输入到 PA1引脚的脉冲信号频率和占空比——约定 PA1 替换成 PB4
2. 通过资源扩展板上的DS18B20（PA6-DS18B20：DQ）获取环境温度数据——这里采用另一路 ADC 模拟实现