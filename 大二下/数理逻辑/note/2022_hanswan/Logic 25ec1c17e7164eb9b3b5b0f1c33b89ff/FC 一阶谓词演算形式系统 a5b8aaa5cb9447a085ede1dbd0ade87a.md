# FC 一阶谓词演算形式系统

## 公理集合

FC 系统共 6 条公理，其中 $A_1$—$A_3$ 为 PC 的公理。

$$
\begin{aligned}
A_1&:A\to(B\to A) \\
A_2&:(A\to(B\to C))\to((A\to B)\to(A\to C)) \\
A_3&:(\neg A\to\neg B)\to(B\to A) \\
A_4&:\forall vA\to A_t^v\qquad t\text{ 对 }v\text{ 可代入} \\
A_5&:\forall v(A\to B)\to(\forall vA\to\forall vB) \\
A_6&:A\to\forall vA\qquad v\text{ 在 }A\text{ 中无自由出现}
\end{aligned}
$$

## 推理规则

### 分离规则

$$
r_{mp}: \frac{A, A\to B}{B}
$$

## 基本定理

下述定理的名字仅为本人为方便记忆所取，并非来自可信来源。

### 定理 1：任取消除

前件的 $\forall$ 可以直接消除。

$$
\vdash_{FC}\forall vA\to A
$$

### 定理 2：存在引入

可以在后件直接引入 $\exist$。

$$
\vdash_{FC}A\to\exist vA
$$

### 定理 3：定理 1 + 定理 2

$$
\vdash_{FC}\forall vA\to\exist vA
$$

### 定理 4：全称推广（1）

对在 FC 中的任何公式 $A$，

$$
\text{if }\vdash A, \text{then}\vdash\forall vA
$$

### 定理 5：全称推广（2）

相当于 Th. 4 加上前提。对 FC 中的任何公式集合 $\Gamma$、公式 $A$ 以及不在 $A$ 中自由出现的变元 $v$，

$$
\text{if }\Gamma\vdash A, \text{then }\Gamma\vdash\forall vA
$$

### 定理 6：演绎定理

$$
\Gamma;A\vdash B\iff\Gamma\vdash A\to B
$$

### 定理 10：存在消除

非常有用。设 $\Gamma$ 为 FC 中任一公式集合，$A$ 和 $B$ 为 FC 中的两公式，$v$ 不在 $\Gamma$ 和 $B$ 中自由出现，

$$
\Gamma\vdash\exist vA, \Gamma; A\vdash B\Rightarrow\Gamma\vdash B
$$

一般的用法是，$\exist vA$ 来自 $\Gamma$（通过 $(\in)$ 得到式 1），$A$ 人工引入（利用 $(\in)$、$(\to-)$ 等得到式 2）。

## 语义和指派

### 语义 / 结构

语义或者说结构是解释「某个命题具体在什么『定义域』上讨论什么问题」，一个语义包含论域 $D$ 和解释 $I$。

例如：对于公式 $\exist xG(x, y)$，一个可能的语义是：

- 论域 $D=\N$；
- 解释 $I$ 为：
    - $G(x,y)$ 对应 $\N$ 上的二元关系 $x < y$。

这样 $\exist xG$ 就有了明确的意义：$\exist x\in\N$，使得 $x<y$。

解释通常用「使谓词为 1 的个体变元的集合」表示，如 $\bar{P}=\{(0,0),(0,1)\}$ 表示对于二元谓词 $P(x, y)$ 当且仅当 $(x, y)=(0,0)$ 或 $(0,1)$ 时为真。

### 指派

对公式中的个体变元进行赋值，使得一个公式的真假可以确定。例如，$s(x)=1$ 即「对公式中的所有个体变元 $x$ 赋值 1」 。

用 $\vDash_{U}A[s]$ 表示「在语义 $U=\langle D, I\rangle$ 和指派 $s$ 下，命题公式 $A$ 为真」。

$\vDash_UA[s]$ 的严格定义：

- 当 $A$ 为原子公式 $P(t_1,t_2,\cdots, t_n)$ 时
    
    $$
    \vDash_UA[s]\iff\langle\bar s(t_1), \bar s(t_2), \cdots, \bar s(t_n)\rangle\in\bar{P}
    $$
    
- 当 $A$ 为 $\neg B$ 时
    
    $$
    \vDash_UA[s]\iff\not\vDash_UB[s]
    $$
    
- 当 $A$ 为 $B\to C$ 时
    
    $$
    \vDash_UA[s]\iff(\not\vDash_UB[s]\text{ 或 }\vDash_UC[s])
    $$
    
- 当 $A$ 为 $\forall vB$ 时
    
    $$
    \vDash_UA[s]\iff\text{对每一个 }d\in D\text{ 有 }\vDash_UB[s(v|d)]
    $$
    
    其中 $s(v|d)$ 的意思是：除了对 $v$ 赋值 $d$ 外，对其他变元的指派与 $s$ 相同。