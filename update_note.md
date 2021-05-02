
<img src='doc/image/icon.png' align='left'/>



<font color=#0CCDD>[<u>**8051-ELL官网**</u>](https://zewen-i.github.io/8051-ELL-WEB/)</font> <font color=#0BBEE>[<u>**全新的API文档中心**</u>](https://zewen-i.github.io/8051-ELL-API/)</font>  

[![](https://img.shields.io/badge/version-1.1.6-green)](https://github.com/zewen-i/8051-ELL-LIB) [![](https://badgen.net/github/license/zewen-i/8051-ELL-LIB?)](https://github.com/zewen-i/8051-ELL-LIB) [![](https://badgen.net/github/stars/zewen-i/8051-ELL-LIB?color=green)](https://github.com/zewen-i/8051-ELL-LIB) [![](https://badgen.net/github/forks/zewen-i/8051-ELL-LIB)](https://github.com/zewen-i/8051-ELL-LIB) <a href='https://gitee.com/zeweni/ELL-8051-LIB/stargazers'><img src='https://gitee.com/zeweni/ELL-8051-LIB/badge/star.svg?theme=white' alt='star'></img></a> <a href='https://gitee.com/zeweni/ELL-8051-LIB/members'><img src='https://gitee.com/zeweni/ELL-8051-LIB/badge/fork.svg?theme=gray' alt='fork'></img></a>



# 更新记录


## 2021年05月

### 2021-05-02

* 修改串口工作相关的函数名，函数名中增加isr，指示需要开启中断。
* 增加SPI中文代码注释，增加串口中文代码注释。
* 增加看门狗中文代码注释。

## 2021年04月

### 2021-04-30

* 修复外部中断4没有配置优先级参数的bug

### 2021-04-29

* 新增RST POWER等模块的中文注释

  

### 2021-04-28

* 新增PCA中文代码注释



### 2021-04-27

* 修复串口2 串口3 串口4 预分频器问题

* 调整启动文件 IDATA初始化范围， 保留存放系统时钟信息的RAM

  

### 2021-04-25

* 优化官网主题

* 增加GPIO中文代码注释

  

### 2021-04-25

* 修改ADC中断采集函数，去掉通道参数，增加切换采集通道宏函数

* 增加I2C中文代码注释
  
  

### 2021-04-24

* 增加GPIO代码中文注释

* 修改端口电平翻转函数名

  

### 2021-04-23

* 增加代码中文注释

* 增加启动文件（汇编）

  

### 2021-04-19

* 增加ADC代码部分中文注释
* 增加TIMER代码部分中文注释，修改定时器结构体句柄的成员Value为Time

### 2021-04-18

* 增加GPIO的Pin宏定义，操作第四位，和操作高四位
* 发布1.1.6版本，库变得更加稳定

### 2021-04-16

* 更新示例，增加PCA做定时器

### 2021-04-11

* 更新两个ADC的例程

## 2021年03月

### 2021-03-31

* 更新STC8H对ADC的支持
* 修复STC8F的类型错误bug

### 2021-03-25

* 更新版权声明

### 2021-03-16

* 更新开发者文档
* 修复比较器读取标志位的宏函数bug

### 2021-03-14

* 优化TMT组件，提高健壮性

* 更新按键扫描驱动，支持高低电平触发，两种按键生效模式

* 更新开发者文档，增加增强型PWM手册 KeyScan手册


### 2021-03-12

* 优化TMT组件，提高健壮性

* 增加各种外设的中断开关宏函数，方便实时控制中断

* 修复STC8A STC8F 串口bug
  

### 2021-03-09

* 增加对STC8C、STC8G、STC8H系列单片机的串口2、3、4中断优先级的适配

* 增加对STC8C、STC8G、STC8H系列单片机的串口波特率发生器预分频的处理

  

### 2021-03-08

* 增加对STC8C系列单片机的适配

  

### 2021-03-06

* 修复STC8H、STC8G 时钟无法读取15M以下频率的bug

  


### 2021-03-03

* 修复STC8H 时钟管理的bug

* 增加STC8G 对ADC的支持 COMP比较器的支持

* 增加STC8G STC8H的硬件16位乘除法运算单元模块

  