<!--
 * @Author: Zhao Huanle
 * @Date: 2022-11-20 20:05:35
 * @LastEditors: Zhao Huanle && zhaohuanle0@gmail.com
 * @LastEditTime: 2022-11-20 20:19:15
 * @Description: 
 * 
 * Copyright (c) 2022 by Zhao Huanle, All Rights Reserved. 
-->
# 编译原理 2020 级
## 1.选择题 2*10
1. 编译程序由什么组成（即整个流程）  
2. 句柄是最左__  
3. 乔姆斯基四种文法的四种语言之间的关系  
4. 词法生成器输出的结果  
5. LR分析中，分析栈存放的状态是识别规范句型的__DFA  
6. SLR（1）的归约要求  
7. G：`S->b|^|(T)`  `T->T * S|S` 求 FISRTOP(T)  
8. 在 `B->B1 or M B2` 中 `B.Truelist` `B.Falselist` 是什么属性  
9. 中间代码形式不可能是什么  
10. 指令开销计算  
## 2.判断题 1*10 
都是简单概念，比如 LL(1) 是其中的 L L 1 什么意思
## 3.填空题 1*10 
同上
## 4.简答题
1.  8 分： 无符号十进制小数用“.”区分，可以 0 开头，比如 03.1415926 ，00.00 ，但不能 0 ，3 ，25 。 写出正则表达式 写出DFA  
2.  8 分： `S->a|^|(T)`  `T -> T,S|S`  写出 `(a,(a,a))` 的 LL(1) 过程 写出某句型的语法树的短语，直接短语，句柄  
3.  10 分：拓展文法 `S’->S`   `S->(T) |a`   `T->T,S|S`  需要计算括号数量，引入属性 num，写出语法制导定义   判断是否是S属性文法
## 5.计算题
1. 18 分： ` D->TL `  `T->int|double`  ` L->id R ` `R->,id R | $\epsilon$`  写 FIRST 和 FOLLOW  判定是否为 LL(1) 文法并画分析表  
2. 12 分： 文法G（E’） ` E‘-> E`   `E->E+id`  `E->id`  求 LR(1) 的 DFA 并画分析表
