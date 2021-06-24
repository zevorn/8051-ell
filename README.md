
<img src='doc/image/icon.png' align='left'/>

# 8051-ELL 库简介

<font color=#0CCDD>[<u>**8051-ELL官网**</u>](https://8051-ell-web.vercel.app/#/)</font>  <font color=#0BBEE>[<u>**全新的API文档中心**</u>](https://8051-ell-api.vercel.app/index.html)</font>   <font color=#0BBEE>[<u>**ELL-知识星球**</u>](https://t.zsxq.com/YBEQF6y)</font>  

[![](https://img.shields.io/badge/version-1.1.6-green)](https://github.com/zewen-i/8051-ELL-LIB) <a href='https://gitee.com/zeweni/ELL-8051-LIB/stargazers'><img src='https://gitee.com/zeweni/ELL-8051-LIB/badge/star.svg?theme=white' alt='star'></img></a> <a href='https://gitee.com/zeweni/ELL-8051-LIB/members'><img src='https://gitee.com/zeweni/ELL-8051-LIB/badge/fork.svg?theme=gray' alt='fork'></img></a>

8051-ELL库，是根据新一代增强型8051为内核的MCU，基于keil开发的硬件抽象平台。ELL库充分考虑8051的特性，结合硬件条件，提供大量标准的API函数，供开发者访问底层硬件细节。并且函数库的大小可裁剪，在代码密度和执行效率上做了很好的平衡。

ELL是`efficient low-layer`的缩写，意思是`高效低封装`，结合了`HAL库`和`LL库`的编程思想，既保证了通用性又降低了flash的过度占用。可谓是一举两得，高效、简洁、好用！

8051-ELL库支持Keil4和Keil5，支持Vscode协同开发，推荐使用EIDE插件。目前ELL库主要适配了STC公司的单片机型号，以STC8系列为主。后续计划增加STC12、STC15、STC16系列。


函数库遵循 Apache 许可证 2.0 版本，可免费在商业产品中使用，不需要公布应用程序源码，没有潜在商业风险。


大家觉得好用的话，记得给个`Star`，我想上自荐！！！！


****
当前版本为：`1.1.6.20210624`

作者微信：ze_wenu

B站账号：泽文i

QQ技术支持群：` 1001220381`


****

## 新手如何入门



进入 <font color=#0CCDD>[<u>**8051-ELL官网**</u>](https://8051-ell-web.vercel.app/#/)</font>  可查看 <font color=#0CCDD>[<u>**入门教程**</u>](https://8051-ell-web.vercel.app/#/zh-cn/start/start)</font> 。



函数库采用了一个裸机框架来组织库文件。框架包括两大部分：`工程文件`和`库文件`。

工程文件主要存放`Keil工程`、`Vscode文件`、`用户代码`。这里可以根据你的编程习惯进行安排，非常的自由！库文件才是我们的重头戏，它主要分为四个部分：`核心文件夹`、`片内外设库`、`组件库`、`设备驱动库`。

### ELL库目录结构


| 一级目录  |  二级目录   |        描述         |
| :-------: | :---------: | :-----------------: |
|    doc    |     ...     |    一些文档资料     |
| examples  |             |      示例工程       |
|           |   STC8Ax    | STC8A系列的示例代码 |
|           |   STC8Cx    | STC8C系列的示例代码 |
|           |     ...     |      其他型号       |
| libraries |             |      ELL库文件      |
|           |    core     |  寄存器和启动文件   |
|           | components  |       组件库        |
|           | peripherals |  芯片的片内外设库   |
|           |   drives    |     设备驱动库      |
|  project  |             |      模板工程       |
|           |   STC8Ax    | STC8A系列的模板工程 |
|           |   STC8Cx    | STC8C系列的模板工程 |
|           |     ...     |      其他型号       |



下面是ELL库的框架图:

![img](doc/image/8051-ELL-FrameWork.png)

整个固件库，充分利用了keil的一些特性，比如使用LX51扩展链接器/定位器，优化了BL51的功能，可以生成更小的目标文件等。


****






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



# 打赏和支持


**如果你觉得ELL库对你有所帮助，可以请我喝杯咖啡！**

<img src="doc/image/赞助码.png" style="zoom:20%;" />

# 技术交流群

欢迎加群，在这里可以帮你解决学习ELL库遇到的问题。

 > <img src="doc/image/QQ交流群.png" style="zoom:30%;" />



# 知识星球

提供对ELL库最完善专业的技术支持，在这里你可以查看使用ELL库中可以接触到的所有技术细节。





<img src="doc/image/知识星球.png" style="zoom:30%;" />