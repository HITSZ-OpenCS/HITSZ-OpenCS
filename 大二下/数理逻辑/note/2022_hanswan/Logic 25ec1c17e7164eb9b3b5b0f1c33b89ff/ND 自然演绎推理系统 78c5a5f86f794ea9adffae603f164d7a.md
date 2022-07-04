# ND 自然演绎推理系统

## 公理集合

共 1 条公理，或者说「公理模式」。

将前提中的任意一项拿出来都能做为结论（显然）。

$$
\Gamma\cup\{A\}\vdash A\qquad(\in)
$$

## 推理规则

这里没有列出 $\neg\neg$（双重否定）和 $\leftrightarrow$ 相关的规则，是因为它们都很显然。

### 假设引入

即 $B\to(A\to B)$，往前提中加料仍然能让原命题成立。

$$
\frac{\Gamma\vdash B}{\Gamma\cup\{A\}\vdash B}\qquad(+)
$$

### 假设消除

即 $\neg A\to(A\to B)$，自相矛盾的原理，也可以理解为拆前件（$A$ 和 $\neg A$ 都不影响正确性，那 $A$ 就没有什么存在意义了）。

$$
\frac{\Gamma;A\vdash B,\Gamma;\neg A\vdash B}{\Gamma\vdash B}\qquad(-)
$$

### 析取引入

即 $A\to A\vee B$，结论随便析取，反正原来那部分总是成立的。

$$
\frac{\Gamma\vdash A}{\Gamma\vdash A\vee B}\qquad(\vee+)
$$

### 析取消除

即 $(A\vee B)\wedge(A\to C)\wedge(B\to C)\to C$。

$$
\frac{\Gamma;A\vdash C,\Gamma;B\vdash C;\Gamma\vdash A\vee B}{\Gamma\vdash C}\qquad(\vee-)
$$

### 合取引入

即 $A\to(B\to A\wedge B)$，两边同时成立时，合取成立。

$$
\frac{\Gamma\vdash A, \Gamma\vdash B}{\Gamma\vdash A\wedge B}\qquad(\wedge+)
$$

### 合取消除

即 $A\wedge B\to A$，合取是很强的条件。

$$
\frac{\Gamma\vdash A\wedge B}{\Gamma\vdash A}\qquad(\wedge-)
$$

### 蕴含引入

即演绎定理。

$$
\frac{\Gamma;A\vdash B}{\Gamma\vdash A\to B}\qquad(\to+)
$$

### 蕴含消除

类似 $r_{mp}$。

$$
\frac{\Gamma\vdash A, \Gamma\vdash A\to B}{\Gamma\vdash B}\qquad(\to-)
$$

### 否定引入

即反证法。$A$ 既能推出 $B$ 又能推出 $\neg B$，那 $A$ 必有问题。

$$
\frac{\Gamma;A\vdash B, \Gamma;A\vdash\neg B}{\Gamma\vdash\neg A}\qquad(\neg+)
$$

### 否定消除

即 $A\to(\neg A\to B)$，自相矛盾，前提必有问题。

$$
\frac{\Gamma\vdash A, \Gamma\vdash\neg A}{\Gamma\vdash B}\qquad(\neg -)
$$

## 基本定理

下面这些定理的名字并非来自教材或其他可信来源，仅为本人为方便记忆而使用。

### 定理 1：否定析取

一个命题和它的否定相析取，得到的东西必然是真的。

$$
\vdash_{ND}A\vee\neg A
$$

### 定理 2：析取化合取

$$
\vdash_{ND}\neg(A\vee B)\leftrightarrow\neg A\wedge\neg B
$$

### 定理 3：合取化析取

$$
\vdash_{ND}\neg(A\wedge B)\leftrightarrow\neg A\vee\neg B
$$

### 定理 4：蕴含化析取（1）

其实就是 $\to$ 的定义。

$$
\neg A\to B\vdash\!\dashv A\vee B
$$

### 定理 5：蕴含化析取（2）

$$
A\to B\vdash\!\dashv\neg A\vee B
$$

### 定理 6：分配律

$$
\begin{aligned}
\vdash_{ND} A\wedge(B\vee C)\leftrightarrow(A\wedge B)\vee(A\wedge C) \\
\vdash_{ND}A\vee(B\wedge C)\leftrightarrow(A\vee B)\wedge(A\vee C)
\end{aligned}
$$

## 做题技巧

### 制造矛盾 + 反证法

利用 $(+)$ 在 $\vdash$ 左侧加上一些东西，然后推出矛盾，再用 $(\neg+)$ 和 $(\neg-)$ 得到结论。比如：证明 $\vdash_{ND}\neg(A\to B)\to A$，可以创造 $A$ 的矛盾：

1. $\neg(A\to B), \neg A\vdash \neg A$   $(\in)$
2. $\neg(A\to B),\neg A\vdash\neg A\wedge B$   $(\wedge+)$
3. $\neg A\wedge B\vdash\!\dashv A\to B$   Th. 5
4. $\vdash\neg A\wedge B\to(A\to B)$   $(\to+)$
5. $\neg(A\to B), \neg A\vdash \neg A\wedge B \to (A\to B)$   $(+)$
6. $\neg(A\to B), \neg A\vdash A\to B$   2, 5 $(\to-)$
7. $\neg(A\to B), \neg A\vdash \neg(A\to B)$   $(\in)$
8. $\neg(A\to B)\vdash\neg\neg A$   6, 7 $(\neg +)$ 
9. $\neg(A\to B)\vdash A$   $(\neg\neg-)$

基本来说，要证什么就把什么的 $\neg$ 放 $\vdash$ 左边。

$(-)$、$(\neg +)$、$(\neg -)$ 都能用来利用矛盾。

### 分拆

1. 利用 $(\wedge+)$，如果右边结论是 $\wedge$ 起来的，就分开证明。
2. 利用 $(\vee-)$，如果条件有 $\vee$ 起来的项，就拆开分别放左边证明，随后用 $(\in)$ 得到析取项。
3. 利用 $(-)$，通过 $(\vee+)$ 扩大范围。比如：

证明 $\vdash(A\vee B)\wedge(\neg B\vee C)\to A\vee C$：

1. $(A\vee B)\wedge(\neg B\vee C), B\vdash(A\vee B)\wedge(\neg B\vee C)$   $(\in)$
2. $(A\vee B)\wedge(\neg B\vee C), B\vdash(\neg B\vee C)$   $(\wedge-)$
3. $\neg B\vee C\vdash\!\dashv B\to C$   Th. 5
4. $\vdash\neg B\vee C\to(B\to C)$   $(\to +)$
5. $(A\vee B)\wedge(\neg B\vee C), B\vdash\neg B\vee C\to(B\to C)$
6. $(A\vee B)\wedge(\neg B\vee C), B\vdash B\to C$   2, 5 $(\to-)$
7. $(A\vee B)\wedge(\neg B\vee C), B\vdash B$   $(\in)$
8. $(A\vee B)\wedge(\neg B\vee C), B\vdash C$   7, 6 $(\to -)$
9. $(A\vee B)\wedge(\neg B\vee C), B\vdash A\vee C$   $(\vee +)$

同理可证 $(A\vee B)\wedge(\neg B\vee C), \neg B\vdash A\vee C$，用 $(-)$ 就可以得到结论。这是一种分类讨论的思想。