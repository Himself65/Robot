## E3RCU的程序源代码
*** 
#### 各种模块介绍（最下方）
### 使用说明
源代码在H1msElf文件夹下
<br>rcu文件需要软件RoboExp打开
<br> +代码已移植成四光电
<br> +基础巡线模块完成
### 下载方法
点击右上角 Clone and Download下的Download ZIP<br>
![github](https://github.com/Himself65/Robot/blob/master/downloadPicture.PNG)  
### 开发
RobotExp V5.3
<br>Miscrosoft Visual Stdio 2017
<br>
<br>
<br>
<br>
<br>
<br>
#### H1msElf.c
主程序，包括基础巡线
#### untilgetline.c
判断程序，直到碰到黑色光电才会跳出循环
##### 使用方法
```c
untilgetline();//直到光电检测到线，才会执行printf
printf("hello,world\n");
