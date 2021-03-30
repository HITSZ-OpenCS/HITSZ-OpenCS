# 1 事件的概率

## 1.1 概率是什么

### 1.1.1 主观概率

反映评估者对一种情况的主观估计的数字，称为主观概率

主观概率可以理解为一种心态或倾向性

根据评估者的经验和知识，主观概率也可有其客观背景

根据其利害关系，评估者的心态将会有倾向性

### 1.1.2 试验与事件

事件的日常用法往往指的是已发生的情况

事件的含义

有一个明确界定的试验

试验前可确认全部可能的结果或结果的范围

界定试验全部可能结果中一确定部分的陈述就是事件

事件是与试验结果有关的一个命题，其正确与否取决于试验结果如何

单一的试验结果称为一个基本事件

一个或一些基本事件并在一起，构成一个事件

### 1.1.3 古典概率

所有结果在试验中有同等可能的出现计划，即等可能的

全部试验结果为有限个，且等可能性成立

在有N个等可能结果的试验中，包含其中M个结果的事件E的概率 $P(E)=M/N$

几何概率将等可能性解释为某个几何属性的相等

### 1.1.4 概率的统计定义

用一个事件在多次重复试验中出现的频率来刻画事件的概率

### 1.1.5 概率的公理化定义

集合 $\Omega$ 

元素 $\omega$ 称为基本事件

 $\Omega$ 的子集构成一个集类 $\mathscr{F}$ 

集类 $\mathscr{F}$ 的每个成员称为事件

$P$ 是定义在 $\mathscr{F}$ 上的函数

$0\leq P(A)\leq 1, A\in\mathscr{F}$

$P(\Omega)=1,P(\varnothing)=0$

## 1.2 古典概率计算

### 1.2.1 排列组合的几个简单公式

$$
\begin{pmatrix} n\\ r \\\end{pmatrix}=\frac{n(n-1)\dotsc(n-r+1)}{r!}
$$

二项式展开公式：


$$
(a+b)^n=\sum_{i=0}^{n}\begin{pmatrix} n\\ i \\\end{pmatrix}a^ib^{n-i}
$$

令 $a=b=1$ 得
$$
\begin{pmatrix} n\\ 0 \\\end{pmatrix}+\begin{pmatrix} n\\ 1 \\\end{pmatrix}+\dotsc+\begin{pmatrix} n\\ n \\\end{pmatrix}=2^n
$$

令 $a=-1,b=1$ 得
$$
\begin{pmatrix} n\\ 0 \\\end{pmatrix}-\begin{pmatrix} n\\ 1 \\\end{pmatrix}+\dotsc+(-1)^n\begin{pmatrix} n\\ n \\\end{pmatrix}=0
$$

由恒等式$( 1 + x ) ^ { m + n } = ( 1 + x ) ^ { m } ( 1 + x ) ^ { n }$可得

$$
\begin{pmatrix} m+n\\ k 
\\\end{pmatrix}=\sum_{i=0}^{k}\begin{pmatrix} m\\ i \\\end{pmatrix}\begin{pmatrix} n\\ k-i \\\end{pmatrix}
$$



$n$ 个相异物件分成 $k$ 堆，各堆物件数分别为 $r_1,\dotsc,r_k$的分法有
$$
\frac{n!}{r_1!\dotsc r_k!}
$$

## 1.3 事件的运算、条件概率与独立性

### 1.3.1 事件的蕴含、包含及相等

当A发生时B必发生，则称A蕴含B，或者说B包含A，记作 $A\subset B$

### 1.3.2 事件的互斥和对立

两事件 $A,B$ 不能在同一次试验中都发生，则称它们是互斥的

$A$的对立事件是$B=\{A不发生\}$，可记作$\overline { A }$

### 1.3.3 事件的和（或称并）

$C=A+B$ 表示 $C = \{A,B至少发生一个\}$

### 1.3.4 概率的加法定理

若干个互斥事件之和的概率等于各事件的概率之和

$P(\overline{A})=1-P(A)$

### 1.3.5 事件的积（或称交）、事件的差

$C=AB$ 表示 $C=\{A,B都发生\}$

$A-B=\{A发生，B不发生\}$

$A-B=A\overline{B}$

### 1.3.6 条件概率

条件概率可以归结为“已知某事件发生了”后计算的概率

在给定 $B$ 发生的条件下 $A$ 的条件概率记作$P(A|B)$

$$
P(A|B)=\frac{P(AB)}{P(B)}
$$

### 1.3.7  事件的独立性,概率乘法定理

若 $P(A) = P(A ∣ B)$, 则 $B$ 的发生与否对 $A$ 发生的可能性毫无影响，这时在概率论上就称 $A,B$ 两事件独立

若$P(A_1\dotsc A_n)= P(A_1)\dotsc P(A_n) $，则称事件 $A_1,\dotsc,A_n$ 相互独立或简称独立 

概率的乘法定理：若干个独立事件$A_1,\dotsc,A_n$之积的概率，等于各事件概率的乘积：$P(A_1\dotsc A_n)= P(A_1)\dotsc P(A_n) $

独立事件的任一部分也独立， 由独立事件决定的事件也独立

若一列事件$A_1,A_2,\dotsc$相互独立,则将其中任一部分改为对立事件时，所得事件列仍为相互独立

相互独立是两两独立的充分非必要条件

### 1.3.8 全概率公式与贝叶斯公式

完备事件群中，各事件两两互斥且每次试验至少发生一个

全概率公式：$P(A)=P(B_1)P(A|B_1)+P(B_2)P(A|B_2)+\dotsc$

贝叶斯公式：

$$
P(B|A)=\frac{P(AB_i)}{P(A)}=\frac{P(B_i)P(A|B_i)}{\sum_{j=1}^{n}P(B_j)P(A|B_j)}
$$

### 1.3.9 重复独立试验、二项概率公式

若一个试验只有两个结果：$A$和$\overline{A}$，则称这个试验为伯努利试验。它的n次重复独立试验称为n重伯努利试验。

设在每次试验中成功的概率为 p ，则在 n 重伯努利试验中成功恰好发生 k 次的概率为


$$
P_n(k)=C_n^k p^k (1-p)^{n-k}
$$

二项概率的泊松逼近

如果$n\to \infty,p\to 0$使得$np=\lambda$保持为正常数
$$
C_n^k p^k (1-p)^{n-k} \to \frac{\lambda^k}{k!}e^{-\lambda}
$$

# 2 随机变量及概率分布

## 2.1 随机变量的概念

随机变量就是试验结果的函数

随机变量分为离散型随机变量和连续型随机变量

## 2.2 离散型随机变量

### 2.2.1 概率分布列

$P(X=x_k)=p_k (k=1,2,\dotsc)$

基本性质：

(i)$p_k \geq 0(k=1,2,\dotsc)$

(ii)$\sum_{k}p_k=1$

### 2.2.2 0—1 分布(伯努利分布、两点分布)

若随机变量 X 只可能取 0 和 1 两个值，且其分布列为

P(X=1)=p

P(X=0)=1-p

则称 X 服从 0—1 分布

### 2.2.3 二项分布

若随机变量 X 的分布列 $P(X=k) = C_n^k p^k (1-p)^{n-k}(k=0,1,\dotsc,n)$

则称 X 服从二项分布，常用记号 X~B(n,p)表示

### 2.2.4 泊松分布

若随机变量 X 的分布列 $P(X=k)=\frac{\lambda^k e^{-\lambda} }{k!}$

则称 X 服从参数为 $\lambda$ 的泊松分布，常用记号 $X~P(\lambda)$表示

### 2.2.5 几何分布

若随机变量 X 的分布列 $P(X=k)=(1-p)^{k-1}p(k=1,2,\dotsc)$

则称 X 服从参数为 p 的几何分布，用记号 X~G(p)表示

实际意义是：前k-1次试验不成功且第k次试验成功的概率

无记忆性：P(X>n+m|X>n)=P(X>m)

### 2.2.6 超几何分布

N 件产品，其中有 M 件次品。从中任取 n 件不同产品，则这 n 件中所含的次品数 X

$P(X=k)=\cfrac{C_M^k C_{N-M}^{n-k} }{C_N^n}$

## 2.3 随机变量的分布函数

$F(x)=P(X\leq x)$为 X 的分布函数

$0 \leq F(x) \leq 1$

$F(x_1) \leq F(x_2),x_1 \leq x_2$

$F(-\infty)=0,F(+\infty)=1$

$F(x^+)=F(x)$，即右连续

## 2.4 连续性随机变量

### 2.4.1 连续型随机变量、概率密度

概率密度是分布函数的导数

已知概率密度函数f(x)，那么分布函数$F(x)=\int_{-\infty}^{x}f(t)\mathrm{d}t$

### 2.4.2 均匀分布

若概率密度 $f(x)= \left\{ \begin{array}{ll}
\frac{1}{b-a} & a\leq x \leq b\\
0 & \textrm{其他}
\end{array} \right.$，那么 X 在区间 [a, b] 上服从均匀分布，记作 X~U[a, b] 。

### 2.4.3 指数分布

若概率密度 $f(x)= \left\{ \begin{array}{ll}
\lambda e^{-\lambda x} &  x > 0\\
0 &  x\leq 0
\end{array} \right.$，那么 X 服从参数为λ的指数分布，记作 X~E[λ] 。

## 2.5 正态分布

若连续型随机变量 X 的概率密度 $f(x)=\frac{1}{\sigma\sqrt{2\pi}}e^{-\frac{(x-\mu)^2}{2\sigma^2}}(-\infty<x<+\infty)$

μ,σ为常数，且σ>0，则称 X 服从参数为 μ,σ 的正态分布，记作 $X \sim N(\mu,\sigma^2)$

N(0,1)称为标准正态分布

一般的正态分布的分布函数F(x)与标准正态分布的分布函数Φ(x)的关系是 $F(x)=\Phi(\frac{x-\mu}{\sigma})$

## 2.6 随机变量函数的分布

设连续型随机变量 X 具有概率密度函数 $f_X(x)$，又设 y = g(x) 为区间 (a, b) 上的严格单调可微函数，则 Y = g(X) 为连续型随机变量且其概率密度函数为 

$f_Y(y)=\left\{ \begin{array}{ll}
f_X(h(y))|h'(y)| &  A<y<B\\
0 &  \textrm{其他}
\end{array} \right.$

其中 h(y)为g(x)的反函数

设连续型随机变量 X 具有概率密度函数 $f(x)$，又设 y = g(x) ，g(x) 在不重叠的区间 $I_1,I_2,\dotsc$上逐段严格单调，其反函数分别为 $h_1(y),h_2(y),\dotsc$，而且$h_1'(y),h_2'(y),\dots$均为连续函数，则 Y=g(x) 为连续型随机变量且其概率密度函数为 

$f_Y(y)=f(h_1(y))|h_1'(y)|+f(h_2(y))|h_2'(y)|+\dotsc $

对于试反函数无意义的 y，密度函数定义为 0

# 4 多维随机变量

## 4.1 多维随机变量及其分布函数、边缘分布函数

设(X,Y)为二维随机变量，x,y 为任意实数，记事件$\{X\leq x\}$与$\{Y\leq y\}$的交为$\{X\leq x,Y \leq y\}$，则二元函数 $F(x,y)=P(X\leq x,Y \leq y)$ 称为(X,Y)的分布函数，或称为 X 和 Y 的联合分布函数。

$P(x_1<X\leq x_2,y_1<Y\leq y_2)=F(x_2,y_2)-F(x_2,y_1)-F(x_1,y_2)+F(x_1,y_1)$

$F_X(x)=F(x,+\infty)$、$F_Y(y)=F(y,+\infty)$为分布函数F(x,y)的边缘分布函数

$F(-\infty,y)=F(x,-\infty)=F(-\infty,-\infty)=0$

$F(+\infty,+\infty)=1$

## 4.2 二维离散型随机变量

$p_{ij}=P(X=x_i,Y=y_j)$

$F(x,y)=\sum\limits_{x_i\leq x} \sum\limits_{y_j\leq y}p_{ij}$

$\sum\limits_{i} \sum\limits_{j}p_{ij}=1$

$P(X=x_i)=\sum\limits_{j=1}^{\infty}p_{ij}=p_{i·}$

$P(Y=y_i)=\sum\limits_{i=1}^{\infty}p_{ij}=p_{·j}$

## 4.3 二维连续型随机变量

### 4.3.1 概率密度及边缘概率密度

若存在非负函数f(x,y)，使得对任意实数x,y有$F(x,y)=\int_{-\infty}^{x}\int_{-\infty}^{y}f(u,v)\mathrm{d}u\mathrm{d}v$

则称(X,Y)为二维连续型随机变量，并称f(x,y)为二维随机变量(X,Y)的概率密度，或称为 X 与 Y 的联合概率密度

若f(x,y)在点(x,y)处连续，则$\frac{\partial^2F(x,y)}{\partial x\partial y}=f(x,y)$

设 G 是 xOy 平面上的一个区域，则点(X,Y)落在 G 中的概率 $P((X,Y)\in G) = \iint\limits_G f(x,y)\mathrm{d}x\mathrm{d}y$

$F_X(x)=F(x,+\infty)=\int_{-\infty}^{+\infty}f(x,y)\mathrm{d}y$

$F_Y(y)=F(+\infty,x)=\int_{-\infty}^{+\infty}f(x,y)\mathrm{d}x$

### 4.3.2 二维均匀分布

设 G 是平面上的有界区域，其面积为 S(G)。若二维随机变量(X,Y)具有概率密度 $f(x,y)=\left\{ \begin{array}{ll}
\frac{1}{S(G)} & (x,y)\in G\\
0 & \textrm{其他}
\end{array} \right.$

则称(X,Y)在G上服从均匀分布

### 4.3.3 二维正态分布

$f(x,y)=\frac{1}{2\pi\sigma_1\sigma_2\sqrt{1-\rho^2}}exp\{-\frac{1}{2(1-\rho^2)}·[\frac{(x-\mu_1)^2}{\sigma_1^2}-2\rho\frac{(x-\mu_1)(y-\mu_2)}{\sigma_1\sigma_2}+\frac{(y-\mu_2)^2}{\sigma_2^2}]\}$

记为$(X,Y)\sim N(\mu_1,\mu_2;\sigma_1^2,\sigma_2^2;\rho)$

## 4.4 随机变量的独立性

若$F(x,y)=F_X(x)F_Y(y)$，则称 X 与 Y 是相互独立的

若X,Y独立，且概率密度函数连续，则$f(x,y)=f_X(x)f_Y(y)$

$(X,Y)\sim N(\mu_1,\mu_2;\sigma_1^2,\sigma_2^2;\rho)$，则 X 与 Y 相互独立的充要条件是 $\rho = 0$

## 4.5 二维随机变量函数的分布

### 4.5.1 和的分布

Z = X + Y

$f_Z(z)=\int_{-\infty}^{+\infty}f(x,z-x)\mathrm{d}x$

$f_Z(z)=\int_{-\infty}^{+\infty}f(z-y,y)\mathrm{d}y$

记作 $f_Z = f_X * f_Y$，称为卷积公式

n 个相互独立的正态变量的线性组合仍然是一个正态变量：$\sum\limits_{i=1}^{n}X_i \sim N(\sum\limits_{i=1}^{n}\mu_i,\sum\limits_{i=1}^{n}\sigma_i^2)$

### 4.5.2 瑞利分布

设 $X,Y$ 是相互独立且服从同一正态分布 $N(0,\sigma^2)$ 的随机变量，$Z = \sqrt{X^2+Y^2}$ ，则：

Z 的分布函数为 $1-e^{-\frac{z^2}{2\sigma^2}}$

Z 的概率密度为 $\frac{z}{\sigma^2}e^{-\frac{z^2}{2\sigma^2}}$

### 4.5.3 max(X,Y)及min(X,Y)的分布

$F_{max}(z)=F_X(z)F_Y(z)$

$F_{min}(z)=1-[1-F_X(z)][1-F_Y(z)]$

## 4.6 条件分布

设二维离散型随机变量 $(X,Y)$ 的分布列 $P(X=x_i,Y=y_j)=p_{ij}$

则 $P(X=x_i|Y=y_j)=\cfrac{p_{ij}}{p_{·j}}$，条件分布为 $P(X\leq x|Y=y)=\cfrac{P(X\leq x,Y=y)}{P(Y=y)}$

对于二维连续型随机变量，条件分布 $P(X\leq x|Y = y) = \lim\limits_{\Delta y\to0^+}P(X\leq x|y-\Delta y < Y \leq y+\Delta y)$，记作 $F_{X|Y}(x|y)$

$Y=y$ 条件下，$X$ 的条件概率密度 $f_{X|Y}(x|y)=\cfrac{f(x,y)}{f_Y(y)}$

# 5 随机变量的数字特征与极限定理

## 5.1 数学期望

### 5.1.1 离散型随机变量的数学期望

离散型随机变量 $X$ 的分布列 $P(X=x_i)=p_i$，其期望为 $E(X)=\sum\limits_{i=1}^{\infty}x_ip_i$，前提是绝对收敛。

二项分布的 $E(X)=np$

泊松分布的 $E(X)=\lambda$

几何分布的 $E(X)=\cfrac{1}{p}$

### 5.1.2 连续型随机变量的数学期望

连续型随机变量 $X$ 的概率密度为 $f(x)$，其期望为 $E(X)=\int_{-\infty}^{+\infty}xf(x)\mathrm{d}x$，前提是绝对收敛。

均匀分布的 $E(X)=\cfrac{a+b}{2}$

正态分布的 $E(X)=\mu$

柯西分布的概率密度为 $f(x)=\cfrac{1}{\pi}\cfrac{1}{1+x^2}$

### 5.1.3 随机变量函数的数学期望

设 $Y=g(X)$，$g(x)$ 是连续函数

若 $X$ 是离散型随机变量，则 $E[Y]=E[g(X)]=\sum\limits_{i=1}^{\infty}g(x_i)p_i$

若 $X$ 是连续型随机变量，则 $E[Y]=E[g(X)]=\int_{-\infty}^{+\infty}g(x)f(x)\mathrm{d}x$

设 $Z=g(X,Y)$，$g(x,y)$ 是连续函数

若 $(X,Y)$ 是二维离散型随机变量，则 $E[Z]=E[g(X,Y)]=\sum\limits_{i=1}^{\infty}\sum\limits_{j=1}^{\infty}g(x_i,y_i)p_{ij}$

若 $(X,Y)$ 是二维连续型随机变量，则 $E[Z]=E[g(X,Y)]=\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}g(x,y)f(x,y)\mathrm{d}x\mathrm{d}y$，且 $E(X)=\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}xf(x,y)\mathrm{d}x\mathrm{d}y$，$E[Y]=\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}yf(x,y)\mathrm{d}x\mathrm{d}y$

### 5.1.4 数学期望的性质

$E(C)=C$

$E(CX)=C·E(X)$

$E(X_1+X_2+\dotsc+X_n)=E(X_1)+E(X_2)+\dotsc+E(X_n)$

如果 $X_1,X_2,\dotsc,X_n$ 相互独立，则 $E(X_1X_2\dotsc X_n)=E(X_1)E(X_2)\dotsc E(X_n)$

## 5.2 方差

### 5.2.1 方差的概念

$X$ 是随机变量，方差 $D(X)=E[X-E(X)]^2$，标准差 $\sigma_x=\sqrt{D(X)}$。

方差计算公式：$D(X)=E(X^2)-[E(X)]^2$

泊松分布的 $D(X)=\lambda$

几何分布的 $D(X)=\cfrac{1-p}{p^2}$

均匀分布的 $D(X)=\cfrac{(b-a)^2}{12}$

指数分布的 $D(X)=\cfrac{1}{\lambda^2}$

正态分布的 $D(X)=\sigma^2$

二项分布的 $D(X)=np(1-p)$

### 5.2.2 方差的性质

$D(C)=0$

$D(CX)=C^2D(X)$

如果 $X_1,X_2,\dotsc,X_n$ 相互独立，则 $D(X_1+X_2+\dotsc+X_n)=D(X_1)+D(X_2)+\dotsc+D(X_n)$

如果 $X,Y$ 相互独立，则 $D(XY)=D(X)D(Y)+D(X)[E(Y)]^2+D(Y)[E(X)]^2$

$D(X)=0$ 的充要条件是 $X$ 取某一常数值 $a$ 的概率为 1

## 5.3 协方差和相关系数、矩

设 $(X,Y)$ 是一个二维随机变量，如果 $\{[X-E(X)][Y-E(Y)]\}$ 存在，则称其为 $X$ 与 $Y$ 的协方差，记作 $Cov(X,Y)$。

$D(X+Y)=D(X)+D(Y)+2Cov(X,Y)$

$Cov(X,Y)=E(XY)-E(X)E(Y)$

$Cov(aX,bY)=abCov(X,Y)$

$Cov(X_1+X_2,Y)=Cov(X_1,Y)+Cov(X_2,Y)$

设 $(X,Y)$ 是一个二维随机变量，如果 $X$ 与 $Y$ 的协方差 $Cov(X,Y)$ 存在，则称 $\cfrac{Cov(X,Y)}{\sqrt{D(x)}\sqrt{D(Y)}}$ 为 $X$ 与 $Y$ 的相关系数，记为 $\rho$

$|\rho|\leq 1$

$|\rho|=1$ 的充要条件是 $P(Y=a+bX)=1$

当 $X$ 与 $Y$ 不相关时，$\rho = 0,Cov(X,Y)=0,D(X+Y)=D(X)+D(Y),E(XY)=E(X)E(Y)$

不相关不一定相互独立，相互独立一定不相关

不相关指的是不存在线性关系，不保证不存在其他关系

若 $E(X^k),(k=1,2,\dotsc)$ 存在，则称 $E(X^k)$ 为随机变量 $X$ 的 $k$ 阶原点矩，常记为 $\alpha_k=E(X^k)$

## 5.4 大数定律

### 5.4.1 切比雪夫不等式

对于任意随机变量 $X$，若它的方差 $D(X)$ 存在，则对于任意 $\varepsilon>0$ 有 $P[|X-E(X)|\geq\varepsilon]\leq\cfrac{D(X)}{\varepsilon^2}$

对于任意正常数 $k$，都有 $P[|X-E(X)|<k\sqrt{D(X)}]\geq 1-\cfrac{1}{k^2}$

### 5.4.2 大数定律

伯努利大数定律：设在 $n$ 重伯努利试验中，成功的次数为 $Y_n$，而在每次试验中成功的概率为 $p$，则对任意 $\varepsilon>0$ 有 $\lim\limits_{n\to{\infty}}P(|\cfrac{Y_n}{n}-p|\geq\varepsilon)=0$

相互独立的随机变量序列 $X_1,X_2,\dotsc,X_n,\dotsc$ 有相同的分布函数，则称其是独立同分布的随机变量序列。

切比雪夫大数定律：设 $\{X_n\}$ 是相互独立的随机变量序列，若存在常数 $C$，使得 $D(X_i)\leq C,(i=1,2,\dotsc)$，则对任意 $\varepsilon>0$ 有 $\lim\limits_{n\to{\infty}}P(|\cfrac{1}{n}\sum\limits_{i=1}^{n}X_i-\cfrac{1}{n}\sum\limits_{i=1}^{n}E(X_i)|\geq\varepsilon)=0$

辛钦大数定律：设 $\{X_n\}$ 是独立同分布的随机变量序列，具有有限的数学期望和方差 $E(X_i)=\mu,D(X_i)=\sigma^2$，具有 $\lim\limits_{n\to{\infty}}P(|\cfrac{1}{n}\sum\limits_{i=1}^{n}X_i-\mu|\geq\varepsilon)=0$

## 5.5 中心极限定理

独立同分布的中心极限定理：如果 $\{X_n\}$ 是独立同分布的随机变量序列，并且具有有限的数学期望和方差$E(X_i)=\mu,D(X_i)=\sigma^2>0$，则对一切 $x\in R$ 有 $\lim\limits_{n\to{\infty}}P(\cfrac{1}{\sqrt{n}\sigma}(\sum\limits_{i=1}^{n}X_i - n\mu)\leq x)=\int_{-\infty}^{x}\cfrac{1}{\sqrt{2\pi}}e^{-\cfrac{t^2}{2}}\mathrm{d}t$

设在 $n$ 重伯努利试验中，成功的次数为 $Y_n$，而在每次试验中成功的概率为 $p$，$q=1-p$，则对一切 $x$ 有 $\lim\limits_{n\to{\infty}}P(\cfrac{Y_n-np}{\sqrt{npq}}\leq x)=\int_{-\infty}^{x}\cfrac{1}{\sqrt{2\pi}}e^{-\cfrac{t^2}{2}}\mathrm{d}t=\Phi(x)$，$P(a<Y_n\leq b)\approx \Phi(\cfrac{b-np}{\sqrt{npq}})-\Phi(\cfrac{a-np}{\sqrt{npq}})$

用正态分布求 $P(Y_n=m)$，可以用 $P(m-0.5<Y_n\leq m+0.5)$ 近似。

# 6 数理统计的基本概念

## 6.1 总体与样本

### 6.1.1 数理统计的基本问题

统计推断的问题可分两类：一类是对未知参数以及对未知概率分布的估计问题；另一类是对未知参数和概率分布的假设检验问题。

### 6.1.2 总体

在数理统计中，人们把所研究的全体元素构成的集合称为总体，而把组成总体的每个元素称为个体。

总体是一个概率分布或者服从这个概率分布的随机变量。

### 6.1.3 样本

人们把从总体 $X$ 中随机抽检或观测 $n$ 个个体的试验称为随机抽样，$n$ 称为容量。

对具体某次抽样来说，抽样结果是 $n$ 个确定的数值：$x_1,x_2,\dotsc,x_n$；而离开了特定的某次抽样来说，抽样结果是 $n$ 个随机变量：$X_1,X_2,\dotsc,X_n$。人们称这 $n$ 个随机变量 $X_1,X_2,\dotsc,X_n$ 为来自总体 $X$ 的一个容量为 $n$ 的样本，而 $x_1,x_2,\dotsc,x_n$ 称为样本的一个观测值，简称样本值。

数理统计的主要任务之一就是研究如何根据样本来推断总体。

假设总体 $X$ 的 $n$ 次观测是在相同条件下独立重复进行的，这样得到的样本 $X_1,X_2,\dotsc,X_n$ 满足两个条件：1. $X_1,X_2,\dotsc,X_n$ 相互独立；2. 每个 $X_i$ 与总体 $X$ 有相同的分布。

满足 1. $X_1,X_2,\dotsc,X_n$ 相互独立；2. 每个 $X_i$ 与总体 $X$ 有相同的分布；的抽样方法称为简单随机抽样，得到的样本称为简单随机样本

简单随机样本的分布可以写成：$P(X_1=x_1,X_2=x_2,\dotsc,X_n=x_n)=\prod\limits_{i=1}^{n}P(X_i=x_i)$

称随机变量 $X$ 的概率分布为一总体，或称随机变量 $X$ 为一总体，而 $X$ 的分布称为总体的分布

如果 $X_1,X_2,\dotsc,X_n$ 是相互独立且与总体 $X$ 有相同分布的 $n$ 个随机变量，即如果它们的联合分布函数 $F^*(x_1,x_2,\dotsc,x_n)=F(x_1)F(x_2)\dotsc F(x_n)$则称 $X_1,X_2,\dotsc,X_n$ 为来自总体 $X$ 的一个容量为 $n$ 的简单随机样本，简称为 $X$ 的一个样本，而 $F^*(x_1,x_2,\dotsc,x_n)$ 就是这个样本的分布函数

## 6.3 $\mathcal{X}^2$ 分布，$t$ 分布和 $F$ 分布

### 6.3.1 $\mathcal{X}^2$ 分布

设 $X_1,X_2,\dotsc,X_n$ 为 $n$ 个相互独立的随机变量，它们都服从标准正态分布 $N(0,1)$ 。$Y=\sum\limits_{i=1}^{n}X_i^2$，则随机变量 $Y$ 的分布称为自由度为 $n$ 的 $\mathcal{X}^2$ 变量，记作 $X\sim\mathcal{X}^2(n)$

$\mathcal{X}^2(n)$ 的概率密度 $f(x)=\cfrac{1}{2^\frac{n}{2}\Gamma(\cfrac{n}{2})}x^{\frac{n}{2}-1}e^{-\frac{x}{2}},(x>0)$

$Y=\sum\limits_{i=1}^{n}X_i^2\sim\mathcal{X}^2(n),E(Y)=n,D(Y)=2n$

设 $X$ 与 $Y$ 是相互独立的随机变量，且 $X\sim\mathcal{X}^2(m),Y\sim\mathcal{X}^2(n)$，则 $Z=X+Y\sim\mathcal{X}^2(m+n)$

### 6.3.2 $t$ 分布

设 $X$ 与 $Y$ 是相互独立的随机变量，且 $X\sim N(0,1),Y\sim\mathcal{X}^2(n)$，则称随机变量 $T=\cfrac{X}{\sqrt{Y/n}}$ 所服从的分布为自由度为 $n$ 的 $t$ 分布，又称学生氏分布，记为 $t(n)$。任何服从 $t(n)$ 分布的随机变量 $T$ 称为自由度 $n$ 的 $t$ 变量，记为 $T\sim t(n)$。

### 6.3.3 $F$ 分布

设 $X$ 与 $Y$ 是相互独立的随机变量，且 $X\sim\mathcal{X}^2(n_1),Y\sim\mathcal{X}^2(n_2)$，则称为随机变量 $F=\cfrac{n_2}{n_1}\cfrac{X}{Y}$ 所服从的分布为第一自由度为 $n_1$，第二自由度 $n_2$ 的 $F$ 分布，记为 $F(n_1,n_2)$。任何服从 $F(n_1,n_2)$ 分布的随机变量 $F$ 称为自由度为 $(n_1,n_2)$ 的 $F$ 变量，记为 $F\sim F(n_1,n_2)$

$F_{1-\alpha}(n_1,n_2)=\cfrac{1}{F_\alpha(n_1,n_2)}$

## 6.4 统计量及抽样分布

设 $X_1,X_2,\dotsc,X_n$ 为总体 $X$ 的容量为 $n$ 的样本，$T(X_1,X_2,\dotsc,X_n)$ 是定义在样本空间上不依赖于未知参数的一个连续函数，则称随机变量 $T(X_1,X_2,\dotsc,X_n)$ 为一个统计量。

设 $X_1,X_2,\dotsc,X_n$ 为总体的一个样本，则统计量 $\bar X=\cfrac{1}{n}\sum\limits_{i=1}^{n}X_i$ 称为样本均值，而统计量 $S^2=\cfrac{1}{n-1}\sum\limits_{i=1}^{n}(X_i-\bar X)^2=\cfrac{1}{n-1}(\sum\limits_{i=1}^{n}X_i^2-n\bar X^2)$ 称为样本方差。

设 $X_1,X_2,\dotsc,X_n$ 为总体 $X$ 的一个样本，$k$ 为任何正整数，则统计量 $\cfrac{1}{n}\sum\limits_{i=1}^{n}X_i^k$ 和 $\cfrac{1}{n}\sum\limits_{i=1}^{n}(X_i-\bar X)^k$ 分别称为样本 $k$ 阶原点矩和样本 $k$ 阶中心距。

设 $X_1,X_2,\dotsc,X_n$ 为总体 $X$ 的一个样本，$x_1,x_2,\dotsc,x_n$ 是样本的一个观测值，将它们按大小次序排列，得到 $x_{(1)}\leq x_{(2)}\leq\dotsc\leq x_{(n)}$。称 $X_{(i)}$ 为第 $i$ 个顺序统计量。将 $M=\left\{ \begin{array}{ll}
X_{(\frac{n+1}{2})},& n\textrm{为奇数} \\
\frac{1}{2}[X_{(\frac{n}{2})}+X_{(\frac{n}{2}+1)} ],& n\textrm{为奇数}
\end{array} \right.$ 称为样本中位数，而将 $R=X_{(n)}-X_{(1)}$ 称为样本极差。

设 $X_1,X_2,\dotsc,X_n$ 为总体 $N(\mu,\sigma^2)$ 的一个样本，则样本均值 $\bar X \sim N(\mu,\cfrac{\sigma^2}{n})$。

设 $\bar X$ 为正态总体 $N(\mu,\sigma^2)$ 的样本均值，则 $\cfrac{\bar X-\mu}{\sigma}\sqrt n \sim N(0,1)$

设 $X_1,X_2,\dotsc,X_n$ 为总体 $N(\mu,\sigma^2)$ 的一个样本，则样本方差 $S^2$ 与样本均值 $\bar X$ 相互独立，且 $\cfrac{n-1}{\sigma^2}S^2\sim\mathcal{X}^2(n-1)$

设 $X_1,X_2,\dotsc,X_n$ 为总体 $N(\mu,\sigma^2)$ 的一个样本， $\bar X$ 与 $S^2$ 分别为样本均值和样本方差，则 $\cfrac{(\bar X-\mu)\sqrt n}{S}\sim t(n-1)$

设 $X_1,X_2,\dotsc,X_{n_1}$ 和 $Y_1,Y_2,\dotsc,Y_{n_2}$ 分别是来自总体 $N(\mu_1,\sigma^2)$ 和 $N(\mu_2,\sigma^2)$ 的两个样本，它们相互独立，则 $\cfrac{\bar X-\bar Y-(\mu_1-\mu_2)}{S_w\sqrt{\cfrac{1}{n_1}+\cfrac{1}{n_2}}}\sim t(n_1+n_2-2)$，其中 $S_w=\sqrt{\cfrac{(n_1-1)S_1^2+(n_2-1)S_2^2}{n_1+n_2-2}}$

设 $X_1,X_2,\dotsc,X_{n_1}$ 和 $Y_1,Y_2,\dotsc,Y_{n_2}$ 分别是来自总体 $N(\mu_1,\sigma^2)$ 和 $N(\mu_2,\sigma^2)$ 的两个样本，它们相互独立，则 $\cfrac{S_1^2/\sigma_1^2}{S_2^2/\sigma_2^2}\sim F(n_1-1,n_2-1)$

设 $X_1,X_2,\dotsc,X_n$ 为任意总体 $X$ 的简单随机样本，则

$E(\bar{X})=E(X)$

$D(\bar{X})=\cfrac{D(X)}{n}$

$E(S^2)=D(X)$

# 7 参数估计

## 7.1 点估计

设 $\theta$ 是总体 $X$ 的未知参数，可以用样本 $X_1,X_2,\dotsc,X_n$ 构成一个统计量 $\hat\theta=\hat\theta(x_1,x_2,\dotsc,x_n)$ 来估计 $\theta$，称 $\hat\theta$ 为 $\theta$ 的估计量。对于具体的样本值 $x_1,x_2,\dotsc,x_n$，估计量 $\hat\theta$ 的值 $\hat\theta(x_1,x_2,\dotsc,x_n)$ 称为 $\theta$ 的估计值，仍简记为 $\hat\theta$。

###  7.1.1 矩估计法

随机变量的一些参数往往本身就是随机变量的矩或者某些矩的函数。

如果可以把未知参数 $\theta$ 用总体矩 $\alpha_k=E(X^k)(k=1,2,\dotsc,m)$ 的函数表示为 $\theta = h(\alpha_1,\alpha_2,\dotsc,\alpha_m)$，那么就可以用样本矩 $A_k=\cfrac{1}{n}\sum\limits_{i=1}^{n}X_i^k$ 估计总体矩 $\alpha_k$，进而用样本矩的函数 $\hat\theta=h(A_1,A_2,\dotsc,A_m)$ 作为未知参数 $\theta$ 的估计，这就是所谓的矩估计法。

设总体 $X$ 的概率密度为 $f(x;\theta_1,\theta_2,\dotsc,\theta_m)$，其中 $\theta_1,\theta_2,\dotsc,\theta_m$ 为未知参数。假定 $X$ 的前 $m$ 阶矩 $\alpha_k=E(X^k)$ 都存在，它们是 $\theta_1,\theta_2,\dotsc,\theta_m$ 的函数，记为 $q_k(\theta_1,\theta_2,\dotsc,\theta_m)$，即 $\alpha_k = \int_{-\infty}^{+\infty}x^kf(x;\theta_1,\theta_2,\dotsc,\theta_m)\mathrm{d}x=q_k(\theta_1,\theta_2,\dotsc,\theta_m)$ ，如果从此方程（组）可解出 $\theta_j=h_j(\alpha_1,\alpha_2,\dotsc,\alpha_m)$，那么当 $\alpha_1,\alpha_2,\dotsc,\alpha_m$ 均未知是，用样本矩 $A_k$ 估计总体矩 $\alpha_k$ ，作替换得 $\hat\theta_j=h_j(A_1,A_2,\dotsc,A_m)$，就是 $\theta_j$ 的据估计。

$\hat\mu=A_1$

$\hat\sigma^2=A_2-A_1^2$

### 7.1.2 最大似然估计法

设总体 $X$ 的概率密度为 $f(x;\theta_1,\theta_2,\dotsc,\theta_m)$，$\theta_1,\theta_2,\dotsc,\theta_m$ 为未知参数，$x_1,x_2,\dotsc,x_n$ 是取自总体 $X$ 的样本值。称 $L=L(\theta_1,\theta_2,\dotsc,\theta_m)=\prod\limits_{i=1}^{n}f(x_i;\theta_1,\theta_2,\dotsc,\theta_m)$ 为似然函数。若有 $\hat\theta_j=\hat\theta_j(x_1,x_2,\dotsc,x_n)$ 使得 $L(\hat\theta_1,\hat\theta_2,\dotsc,\hat\theta_m)=\max L(\theta_1,\theta_2,\dotsc,\theta_m)$ ，则称 $\hat\theta_j=\hat\theta_j(X_1,X_2,\dotsc,X_n)$ 为 $\theta_j$ 的最大似然估计量 $(j=1,2,\dotsc,m)$

通常采用解似然方程（组）$\cfrac{\partial\ln L}{\partial\theta_j}=0,(j=1,2,\dotsc,m)$ ，求得 $\ln L$ 的驻点，然后找出使似然函数最大的 $\hat\theta_j$。

### 7.1.3 鉴定估计量的标准

无偏性

设 $\hat\theta=\hat\theta(x_1,x_2,\dotsc,x_n)$ 是 $\theta$ 的估计量，若对任何可能的参数值 $\theta$ 都有 $E_\theta[\hat\theta(X_1,X_2,\dotsc,X_n)]=\theta$，则称 $\hat\theta$ 是未知参数 $\theta$ 的无偏估计量。

无偏性表示 $\hat\theta$ 围绕被估计参数 $\theta$ 而摆动，没有系统性误差。

用 $E_\theta(T)$ 和 $D_\theta(T)$ 分别表示随机变量 $T$ 的概率分布中的参数值为 $\theta$ 时，随机变量 $T$ 的数学期望和方差。

有效性

设 $\hat\theta=\hat\theta(x_1,x_2,\dotsc,x_n)$ 和 $\hat\theta^\prime=\hat\theta^\prime(x_1,x_2,\dotsc,x_n)$ 都是 $\theta$ 的无偏估计，如果对任何可能的参数值 $\theta$ 都有 $D_\theta(\hat\theta)\leq D_\theta(\hat\theta^\prime)$，且至少对某个参数值 $\theta_0$ 使小于号成立，则称 $\hat\theta$ 较 $\hat\theta^\prime$ 有效

相合性

如果 $\hat\theta_n=\hat\theta_n(X_1,X_2,\dotsc,X_n)$ 依概率收敛于 $\theta$，即对于任意的 $\varepsilon>0$ 有 $\lim\limits_{n\to{\infty}}P(|\hat\theta_n-\theta|\geq\varepsilon)=0$，则称估计量 $\hat\theta_n$ 是未知参数 $\theta$ 的相合估计量。

## 7.2 区间估计

对未知参数 $\theta$，如果有两个统计量 $\hat\theta_1=\hat\theta_1(x_1,x_2,\dotsc,x_n)$，$\hat\theta_2=\hat\theta_2(x_1,x_2,\dotsc,x_n)$ 对于给定的 $\alpha\in(0,1)$ 有 $P(\hat\theta_1<\theta<\hat\theta_2)=1-\alpha$，则称 $(\hat\theta_1,\hat\theta_2)$ 为 $\theta$ 的置信区间，$1-\alpha$ 为置信度，$\hat\theta_1$ 和 $\hat\theta_2$ 分别为置信下限和置信上限。

### 7.2.1 单个正态总体参数的区间估计

1. $\sigma^2$ 已知，求 $\mu$ 的置信区间

由式 $u=\cfrac{\bar x-\mu}{\sigma}\sqrt{n}\sim N(0,1)$ 对给定的 $\alpha$，查得临界值 $u_{\frac{\alpha}{2}}$ 使得 $P(-u_{\frac{\alpha}{2}}<u<u_{\frac{\alpha}{2}})=1-\alpha$，将 $u$ 的公式代入可得 $\mu$ 的置信区间为 $(\bar x-u_{\frac{\alpha}{2}}\cfrac{\sigma}{\sqrt{n}},\bar x+u_{\frac{\alpha}{2}}\cfrac{\sigma}{\sqrt{n}})$

2. $\sigma^2$ 未知，求 $\mu$ 的置信区间

由式 $\cfrac{(\bar X-\mu)\sqrt n}{S}\sim t(n-1)$ 对给定的 $\alpha$，查得临界值 $t_{\frac{\alpha}{2}}(n-1)$ 使得 $P(-t_{\frac{\alpha}{2}}(n-1)<t<t_{\frac{\alpha}{2}}(n-1))=1-\alpha$，将 $u$ 的公式代入可得 $\mu$ 的置信区间为 $(\bar x-t_{\frac{\alpha}{2}}(n-1)\cfrac{s}{\sqrt{n}},\bar x+t_{\frac{\alpha}{2}}(n-1)\cfrac{s}{\sqrt{n}})$

3. 求 $\sigma^2$ 的置信区间

由式 $\mathcal{X}^2=\cfrac{n-1}{\sigma^2}S^2\sim\mathcal{X}^2(n-1)$ 对给定的 $\alpha$，查得临界值 $\mathcal{X}_{1-\frac{\alpha}{2}}^2(n-1)$ 与 $\mathcal{X}_{\frac{\alpha}{2}}^2(n-1)$ 使得 $P(\mathcal{X}_{1-\frac{\alpha}{2}}^2(n-1)<u<\mathcal{X}_{\frac{\alpha}{2}}^2(n-1))=1-\alpha$，将 $\mathcal{X}^2$ 的公式代入可得 $\sigma^2$ 的置信区间为 $(\cfrac{(n-1)s^2}{\mathcal{X}_{\frac{\alpha}{2}}^2(n-1)},\cfrac{(n-1)s^2}{\mathcal{X}_{1-\frac{\alpha}{2}}^2(n-1)})$

### 7.2.2 两个正态总体参数的区间估计

1. 已知 $\sigma_1^2=\sigma_2^2$，求 $\mu_1-\mu_2$ 的置信区间
2. 求 $\cfrac{\sigma_1^2}{\sigma_2^2}$ 的置信区间