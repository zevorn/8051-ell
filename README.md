
<img src='doc/image/icon.png' align='left'/>

# 8051-ELL 库简介

<font color=#0BBEE>[ <u>**全新的API文档中心**</u>](https://zewen-i.github.io/8051-ELL-library-API-Document-Center/) </font> 

[![](https://badgen.net/github/license/zewen-i/8051-ELL-LIB?color=orange)](https://github.com/zewen-i/8051-ELL-LIB) [![](https://badgen.net/github/stars/zewen-i/8051-ELL-LIB?color=green)](https://github.com/zewen-i/8051-ELL-LIB) [![](https://badgen.net/github/forks/zewen-i/8051-ELL-LIB)](https://github.com/zewen-i/8051-ELL-LIB) <a href='https://gitee.com/zeweni/ELL-8051-LIB/stargazers'><img src='https://gitee.com/zeweni/ELL-8051-LIB/badge/star.svg?theme=white' alt='star'></img></a> <a href='https://gitee.com/zeweni/ELL-8051-LIB/members'><img src='https://gitee.com/zeweni/ELL-8051-LIB/badge/fork.svg?theme=gray' alt='fork'></img></a>


8051-ELL库，是根据新一代增强型8051为内核的MCU，基于keil开发的软件包。函数库采用了LL库的编程思想，充分考虑8051的特性，结合硬件条件，提供大量标准的API函数，供开发者访问底层硬件细节。并且函数库的大小可裁剪，在代码密度和执行效率上做了很好的平衡。


为考虑函数库的兼容性，我在编写规则及注释上面选择了全英文的方式，若开发者不习惯全英文，可以通过库函数提供的开发者文档了解API函数的具体使用方法，我们在文档里提供了详细丰富的中文注解和说明。
（下一个版本讲在库代码中引入中文注释！编码格式为UTF-8，支持Keil和VScode 无缝切换）


函数库遵循 Apache 许可证 2.0 版本，可免费在商业产品中使用，不需要公布应用程序源码，没有潜在商业风险。


大家觉得好用的话，记得给个Star，我想上自荐！！！！

****

<font color=#0BBEE>[ <u>**全新的API文档中心**</u>](https://zewen-i.github.io/8051-ELL-library-API-Document-Center/) </font> 

[下载连接(gitee仓库)](https://gitee.com/zeweni/ELL-8051-LIB)

[下载连接(github仓库)](https://github.com/zewen-i/8051-ELL-LIB)

[开发指南视频链接](https://www.bilibili.com/video/BV1EU4y1s736?from=search&seid=5098754810768350553)

配套核心板购买连接（待上架）


****
当前版本为：`1.1.6`

版本更新时间：`2021.04.23`


作者微信：ze_wenu

B站账号：泽文i


****



## 下一个版本的特性预览



* 增startup.asm汇编文件，用于集中处理堆栈、可重入、**硬件仿真调试（完美支持）**、Keil中断号超出的问题

* 取消NVIC.c NVIC.h 文件，相关类型定义和中断号宏定义，转移至ELL_CORE.h文件

* 相应中断功能和引脚切换复用功能函数，移动至对应模块下，方便操作。

* 增加中英文注释，采用UTF-8编码。

* 修复若干个bug

* 配套新版开发者文档（陆续推出）

  

## ELL库介绍

ELL是`efficient low-layer`的缩写，意思是`高效低封装`，结合了`HAL库`和`LL库`的编程思想，既保证了通用性又降低了flash的过度占用。可谓是一举两得，高效、简洁、好用！



开发函数库，最初是为了满足我自己的生产需求，后来经过深思熟虑，我想做一个好用的通用库，所以把它开源出来，分享给广大工程师们。



函数库是基于Keil开发，支持Keil4和Keil5，支持Vscode协同开发，推荐使用EIDE插件。目前函数库主要适配了STC公司的单片机型号，以STC8系列为主。后续计划增加STC12、STC15、STC16系列。



## 新手如何入门



如果你明白了ELL函数库的架构，那么对你学习本库会有非常大的帮助！函数库采用了一个裸机框架来组织库文件。框架包括两大部分：`工程文件`和`库文件`。



工程文件主要存放`Keil工程`、`Vscode文件`、`用户代码`。这里可以根据你的编程习惯进行安排，非常的自由！库文件才是我们的重头戏，它主要分为四个部分：`核心文件夹`、`片内外设库`、`组件库`、`设备驱动库`。



****

核心文件夹：
存放各种MCU的寄存器头文件、函数库重定义数据类型头文件、函数库常用数据结构头文件

片内外设库：
存放MCU的片内外设模块，是库的主要构成单元。

组件库：
配套8051内核开发的好用组件，具有一定的抽象性和封装性，能加速项目的开发，比如TMT时间片任务进程组件。

设备驱动库：
一些常用的外围芯片、模块，通过统一的驱动框架进行封装，方便开发。

****



下面是ELL库的框架图:

![img](doc/image/8051-ELL-FrameWork.png)

整个固件库，充分利用了keil的一些特性，比如使用LX51扩展链接器/定位器，优化了BL51的功能，可以生成更小的目标文件等



# 开发者文档


<font color=#0BBEE>[ <u>**全新的API文档中心**</u>](https://zewen-i.github.io/8051-ELL-library-API-Document-Center/) </font> 

[ELL库概要介绍](https://zeweni.gitee.io/2021/02/18/8051ell-ku-gai-yao-jie-shao/)

[ELL库工程创建](https://zeweni.gitee.io/2021/02/18/8051ell-ku-gong-cheng-chuang-jian/)

[ELL库代码烧录](https://zeweni.gitee.io/2021/03/16/8051ell-ku-dai-ma-shao-lu/)



## 片内外设库



[时钟管理](https://zeweni.gitee.io/2021/03/02/8051ell-ku-pian-nei-wai-she-pian-shi-zhong-guan-li/)

[中断管理](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-zhong-duan-guan-li/)

[电源管理](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-dian-yuan-guan-li/)

[复位功能](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-fu-wei-gong-neng/)

[看门狗](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-kan-men-gou/)

[IO口](https://zeweni.gitee.io/2021/03/02/8051ell-ku-pian-nei-wai-she-pian-io-kou/)

[定时器](https://zeweni.gitee.io/2021/03/02/8051ell-ku-pian-nei-wai-she-pian-ding-shi-qi/)

[串口](https://zeweni.gitee.io/2021/03/04/8051ell-ku-pian-nei-wai-she-pian-chuan-kou/)

[ADC](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-12-wei-adc/)

[比较器](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-bi-jiao-qi/)

[可编程计数器](https://zeweni.gitee.io/2021/03/01/8051ell-ku-pian-nei-wai-she-pian-ke-bian-cheng-ji-shu-qi/)

[增强型PWM](https://zeweni.gitee.io/2021/03/14/8051ell-ku-pian-nei-wai-she-pian-zeng-qiang-xing-pwm/)

[SPI](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-spi/)

[I2C](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-i2c/)

[MDU16](https://zeweni.gitee.io/2021/03/16/8051ell-ku-pian-nei-wai-she-pian-mdu16/)

[其他暂未更新](https://zeweni.gitee.io/categories/8051-ELL%E5%87%BD%E6%95%B0%E5%BA%93%E6%8C%87%E5%8D%97/)



## 组件库



[任务管理工具](https://zeweni.gitee.io/2021/03/01/8051ell-ku-zu-jian-pian-ren-wu-guan-li-gong-ju/)

[其他暂未更新](https://zeweni.gitee.io/categories/8051-ELL%E5%87%BD%E6%95%B0%E5%BA%93%E6%8C%87%E5%8D%97/)



## 设备驱动库


[按键扫描](https://zeweni.gitee.io/2021/03/14/8051ell-ku-she-bei-qu-dong-pian-an-jian-sao-miao-dan-jian/)

[暂未更新](https://zeweni.gitee.io/categories/8051-ELL%E5%87%BD%E6%95%B0%E5%BA%93%E6%8C%87%E5%8D%97/)



# 支持的型号及外设

> `√`代表已经支持、`空`代表MCU没有这个外设、 ` X`代表还没有适配



### STC8系列

部分型号可能有所差异，详情可查看官方数据手册。

| 型号      | 定时器 | IO   | 中断 | 系统时钟 | PCA  | PWM  | MPWM | HPWM | EEPROM | ADC  | MDU16 | 比较器 | USB  | LED | RTC | TKEY |
| --------- | ----- | ---- | ---- | -------- | ---- | ---- | ---- | ------ | ---- | ----- | ------ | ---- | ---- | ---- | ---- | ---- |
| STC8A系列 | √      | √    | √    | √       | √    | √    | X    | X   | √      | √    |       | √      |      |      |      |      |
| STC8C系列 | √      | √    | √    | √       |      |      |      |      | √      |      | √     | √      |      |      |      |      |
| STC8F系列 | √      | √    | √    | √       |    |      |      |      | √      |      |       | √      |      |      |      |      |
| STC8G系列 | √      | √    | √    | √       | √    |   | X |      | √      | √    | √     | √      | X | X |      |      |
| STC8H系列 | √      | √    | √    | √       |     |      |  | X | √      | √    | √     | √      | X | X | X | X |





# 更新记录

## 2021年04月

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

  