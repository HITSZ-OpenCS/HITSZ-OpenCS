数逻实验三

## 1、实验目的

（1）掌握控制七段数码管显示的方法；

（2）深化对计数器架构时序电路的理解；

（3）掌握较复杂时序电路的开发与调试，锻炼数字电路分析能力。

## 2、实验内容

设计数码管控制器，要求能够控制8个数码管（从左往右DK7-DK0）同时稳定地显示数字，要求如下：

- DK7-DK6显示自己学号后两位；
- DK5-DK4显示拨码开关SW7-SW0输入的1的个数；
- DK3-DK2显示输入计数，读取按键开关S3，每按一次计数一次，要求实现稳定计数，持续按住只计数一次；
- DK1-DK0显示十进制计数，实现一个计数间隔为0.1s的从0到20的十进制计数器，复位后直接开始计数，计数到20后保持住，按下S2后重启计数
- 按键开关S2作为十进制计数器控制信号，当计数器计数到十进制20时，按下S2再重启计数。
- 按键开关S1作为异步复位信号，当S1按下为1时，数码管模块将被复位，复位状态的显示自行决定；
- 工程名为led_display_ctrl；核心模块RTL文件命名为led_display_ctrl.v；

##### 以上引自飞书

#### 思路：

##### 1、计数器的设计：

该实验会使用多个计数器，比如我想要个每0.1s就计时一次的计数器，我只需要将T=10ns的clk分频，每1T计数一次，到10000000再重新计时：

```verilog
reg [23:0] cnt;
always @ (posedge clk or posedge rst)
begin
    if (rst) cnt <= 0;
    else if (cnt >= 10000000) cnt <= 0;
    else cnt <= cnt + 1;
end
```

最后在另外的$always$块中把`(cnt >= 10000000)`作为if语句条件便能将每次计时结果输出

在此基础上设计比如20次0.1s的计数器就是计数器外再套一个计数器

##### 2、按钮的设计：

按钮一般使用级联进行变化判断，如二级联：

```verilog
input button);
reg sig_r0,sig_r1;
wire sig_detect;
assign sig_detect = sig_r0 & (~sig_r1);

always @ (posedge clk)
begin
    if (rst) sig_r0 <= 0;
    else sig_r0 <= button;
end

always @ (posedge clk)
begin
    if (rst) sig_r1 <= 0;
    else sig_r1 <= sig_r0;
end
```

输出的`sig_detect`信号便是变化信号，但是由于本身机械结构的问题，在按下按钮后`button`会在一定时间产生0和1之间的抖动，导致信号输出不像预料那样，故可以加入如10ms延时，在检测到信号变化，告知其他模块信号发生变化后，在一定时间内不能再次告知：

```verilog
reg [19:0] dismiss;
reg cnt_inc,cnt_end;
reg button_detect;

always @ (posedge clk or posedg rst)
begin
    if (rst) begin
    cnt_inc <= 0;
    cnt_end <= 0;end
    else if (sig_detect) cnt_inc <= 1;
    else if (cnt_end) cnt_inc <= 0;
    else if (dismiss >= 1000000) cnt_end <= 1;
    else if (button_detect) cnt_end <= 0;
end

always @ (posedge clk)
begin
    if (rst) dismiss <= 0;
    else if (cnt_inc) dismiss <= dismiss + 1;
    else if (cnt_end) dismiss <= 0;
end

always @ (posedge clk or posedge rst)
begin
    if (rst) button_detect <= 0;
    else if (cnt_inc && cnt_end) button_detect <= 1;
    else button_detect <= 0;
end
```

将`button_detect`作为按钮的输出即可

##### 3、数码管的显示：

首先虽然板子上有8个显示数字的数码管，使能信号存储在`[7:0] led_en`中，但是它们的“数字”输入`led_cx`都是一样的，所以我们要每2ms将要显示的数字交替输入给需要显示的数码管，通过视觉的暂留效应达到8个数码管都能“同时”显示的目的，所以我们先假设有一个周期为2ms的计数器，其输出为`(cnt_flash >= 200000)`，并且已有寄存器`reg [7:0] lednum [7:0]`来储存每一个数码管将要显示的“数字”，有寄存器`reg [7:0] cnt`来储存在`(cnt_flash >= 200000)`循环中的数码管对应位置号的变化（注意：该数码管是共阴极，即0为使能电平）：

```verilog
if (cnt_flash >= 200000)
    begin
    if (cnt == 0) begin
    led_en[0] <= 0;
    led_cx <=  lednum[0];
    led_en[7] <= 1;end
    //***//
    else if (cnt == 7) begin
    led_en[7] <= 0;
    led_cx <= lednum[7];
    led_en[6] <= 1;end
if (cnt >=  7) cnt <= 0;
else cnt <= cnt + 1;
```

其次就是将所要输出的“数字”信号输入给寄存器$lednum$中，可以用case或if-else语句，判断条件用到除10余10等方法

还有就是“数字”的表示方法，这种可以直接上网搜得到

````verilog
0为8'b00000011
1为8'b10011111
2为8'b00100101
3为8'b00001101
4为8'b10011001
5为8'b01001001
6为8'b01000001
7为8'b00011111
8为8'b00000001
9为8'b00001001
```

直接赋值给lednum就OK了