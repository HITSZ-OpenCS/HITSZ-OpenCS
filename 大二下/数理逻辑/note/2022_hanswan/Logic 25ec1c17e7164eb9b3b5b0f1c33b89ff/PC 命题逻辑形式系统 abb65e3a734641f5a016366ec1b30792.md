# PC 命题逻辑形式系统

## 公理集合

共三条公理，或者说「公理模式」：

### 公理 1：加前件

$$
A\to(B\to A)
$$

### 公理 2：拆后件

$$
(A\to(B\to C))\to((A\to B)\to(A\to C))
$$

### 公理 3：逆否（1）

$$
(\neg A\to\neg B)\to(B\to A)
$$

## 推理规则

### 分离规则

$$
r_{mp}: \frac{A, A\to B}{B}
$$

或者写成公式串的形式：

$$
A, A\to B, B
$$

## 基本定理

### 定理 1：反身

一个命题公式是蕴含它自己的。

$$
\vdash_{PC}A\to A
$$

- 证明
    1. $(A\to((B\to A)\to A))\to ((A\to(B\to A))\to(A\to A))$   $A_2$
    2. $A\to((B\to A)\to A)$   $A_1$
    3. $(A\to(B\to A))\to(A\to A)$   2, 1 $r_{mp}$
    4. $A\to(B\to A)$   $A_1$
    5. $A\to A$   4, 3 $r_{mp}$

### 定理 2：前件互换（演绎形式）

交换前件和「后件的前件」。

$$
\vdash_{PC}A\to(B\to C)\iff\vdash_{PC}B\to(A\to C)
$$

- 证明
    1. $A\to(B\to C)$   前提
    2. $(A\to(B\to C))\to((A\to B)\to(A\to C))$   $A_2$
    3. $(A\to B)\to(A\to C)$   1, 2 $r_{mp}$
    4. $((A\to B)\to(A\to C))\to(B\to((A\to B)\to(A\to C)))$   $A_1$
    5. $B\to((A\to B)\to(A\to C))$   3, 4 $r_{mp}$
    6. $(B\to((A\to B)\to(A\to C)))\to((B\to(A\to B))\to(B\to(A\to C)))$   $A_2$
    7. $(B\to(A\to B))\to(B\to(A\to C))$   5, 6 $r_{mp}$
    8. $B\to(A\to B)$   $A_1$
    9. $B\to(A\to C)$   7, 8 $r_{mp}$

### 定理 3：前件互换（定理形式）

交换前件和「后件的前件」。

$$
\vdash_{PC}(A\to(B\to C))\to(B\to(A\to C))
$$

- 证明
    1. $(A\to (B\to C))\to((A\to B)\to(A\to C))$   $A_2$
    2. $(A\to B)\to((A\to(B\to C))\to(A\to C))$   1 Th. 2
    3. $((A\to B)\to((A\to(B\to C))\to(A\to C)))\to(B\to((A\to B)\to((A\to(B\to C))\to(A\to C))))$   $A_1$
    4. $B\to((A\to B)\to((A\to(B\to C))\to(A\to C)))$   2, 3 $r_{mp}$
    5. $(B\to((A\to B)\to((A\to(B\to C))\to(A\to C)))) \to ((B\to(A\to B))\to(B\to((A\to(B\to C))\to(A\to C))))$   $A_2$
    6. $(B\to(A\to B))\to(B\to((A\to(B\to C))\to(A\to C)))$   4, 5 $r_{mp}$
    7. $B\to(A\to B)$   $A_1$
    8. $B\to((A\to(B\to C))\to(A\to C))$   7, 6 $r_{mp}$
    9. $(A\to(B\to C))\to(B\to(A\to C))$   8 Th. 2

### 定理 4：加前件

给前件和后件同时加上同一个前件。

$$
\vdash_{PC}(B\to C)\to((A\to B)\to(A\to C))
$$

- 证明
    1. $(A\to (B\to C))\to((A\to B)\to(A\to C))$   $A_2$
    2. $((A\to (B\to C))\to((A\to B)\to(A\to C)))\to((B\to C)\to ((A\to (B\to C))\to((A\to B)\to(A\to C))))$   $A_1$
    3. $(B\to C)\to ((A\to (B\to C))\to((A\to B)\to(A\to C)))$   1, 2 $r_{mp}$
    4. $((B\to C)\to ((A\to (B\to C))\to((A\to B)\to(A\to C))))\to (((B\to C)\to(A\to(B\to C)))\to((B\to C)\to((A\to B)\to (A\to C)))$   $A_2$
    5. $((B\to C)\to(A\to(B\to C)))\to((B\to C)\to((A\to B)\to (A\to C))$   3, 4 $r_{mp}$
    6. $(B\to C)\to(A\to(B\to C))$   $A_1$
    7. $(B\to C)\to((A\to B)\to(A\to C))$   5, 6 $r_{mp}$

### 定理 5：加后件

将前件和后件调换后，给它们加上同一个后件。

$$
\vdash_{PC}(A\to B)\to((B\to C)\to (A\to C))
$$

- 证明
    1. $(B\to C)\to((A\to B)\to (A\to C))$   Th. 4
    2. 上面的东西换前件

### 定理 6：自相矛盾（1）

既然你都承认 $\neg A$ 了，那 $A$ 不就可以推出任何东西了吗？

$$
\vdash_{PC}\neg A\to(A\to B)
$$

- 证明
    1. $(\neg B\to\neg A)\to(A\to B)$   $A_3$
    2. $((\neg B\to\neg A)\to(A\to B))\to(\neg A\to((\neg B\to\neg A)\to(A\to B)))$   $A_1$
    3. $\neg A\to((\neg B\to\neg A)\to(A\to B))$   1, 2 $r_{mp}$
    4. $(\neg A\to((\neg B\to\neg A)\to(A\to B)))\to ((\neg A\to(\neg B\to\neg A))\to(\neg A\to(A\to B)))$   $A_2$
    5. $(\neg A\to(\neg B\to\neg A))\to(\neg A\to(A\to B))$   3, 4 $r_{mp}$
    6. $\neg A\to(\neg B\to\neg A)$   $A_1$
    7. $\neg A\to(A\to B)$   5, 6 $r_{mp}$

### 定理 7：自相矛盾（2）

与 Th. 6 相似。

$$
\vdash_{PC}A\to(\neg A\to B)
$$

- 证明
    1. $\neg A\to(A\to B)$   Th. 6
    2. 换前件

### 定理 8：三段论

苏格拉底的三段论，现更以 PC 中的定理方式呈现。

$$
\text{if }\vdash A\to B, \vdash B\to C, \text{then } \vdash A\to C 
$$

- 证明
    1. $A\to B$   前提
    2. $B\to C$   前提
    3. $(A\to B)\to((B\to C)\to(A\to C))$   Th. 5
    4. $(B\to C)\to(A\to C)$   1, 3 $r_{mp}$
    5. $A\to C$   2, 4 $r_{mp}$

### 定理 9：反证法（1）

自己的否定蕴含自身。

$$
\vdash_{PC}(\neg A\to A)\to A
$$

- 证明
    1. $\neg A\to(A\to\neg(\neg A\to A))$   Th. 6
    2. $(\neg A\to(A\to\neg(\neg A\to A)))\to((\neg A\to A)\to(\neg A\to\neg(\neg A\to A)))$   $A_2$
    3. $(\neg A\to A)\to(\neg A\to\neg(\neg A\to A))$   1, 2 $r_{mp}$
    4. $(\neg A\to\neg(\neg A\to A))\to((\neg A\to A)\to A)$   $A_3$
    5. $(\neg A\to A)\to((\neg A\to A)\to A)$   3, 4 Th. 8
    6. $((\neg A\to A)\to((\neg A\to A)\to A))\to(((\neg A\to A)\to(\neg A\to A))\to((\neg A\to A)\to A))$   $A_2$
    7. $((\neg A\to A)\to(\neg A\to A))\to((\neg A\to A)\to A)$   5, 6 $r_{mp}$
    8. $(\neg A\to A)\to(\neg A\to A)$   Th. 1
    9. $(\neg A\to A)\to A$   8, 7 $r_{mp}$
    

### 定理 10：双重否定（1）

双重否定表肯定。

$$
\vdash_{PC}\neg\neg A\to A
$$

- 证明
    1. $\neg\neg A\to(\neg A\to A)$   Th. 6
    2. $(\neg A\to A)\to A$   Th. 9
    3. $\neg\neg A\to A$   1, 2 Th. 8
    

### 定理 11：反证法（2）

同 Th. 9。

$$
\vdash_{PC}(A\to\neg A)\to\neg A
$$

- 证明
    1. $\neg\neg A\to A$   Th. 10
    2. $(\neg\neg A\to A)\to((A\to\neg A)\to(\neg\neg A\to \neg A))$   Th. 5
    3. $(A\to\neg A)\to(\neg\neg A\to \neg A)$   1, 2 $r_{mp}$
    4. $((A\to\neg A)\to(\neg\neg A\to \neg A))\to(((\neg\neg A\to\neg A)\to\neg A)\to((A\to\neg A)\to\neg A))$   Th. 5
    5. $((\neg\neg A\to\neg A)\to\neg A)\to((A\to\neg A)\to\neg A)$   3, 4 $r_{mp}$
    6. $(\neg\neg A\to \neg A)\to\neg A$   Th. 9
    7. $(A\to\neg A)\to\neg A$   6, 5 $r_{mp}$

### 定理 12：双重否定（2）

同 Th. 10。

$$
\vdash_{PC}A\to\neg\neg A
$$

- 证明
    1. $(\neg A\to\neg\neg A)\to\neg\neg A$   Th. 11
    2. $A\to(\neg A\to\neg\neg A)$   Th. 7
    3. $A\to\neg\neg A$   1, 2 Th. 8
    

### 定理 13—15：逆否（2—4）

这三条定理和 $A_3$ 共同描述了「逆否命题」。

- $A_3$: $\vdash(\neg B\to\neg A)\to(A\to B)$
- Th. 13: $\vdash(A\to B)\to(\neg B\to\neg A)$
- Th. 14: $\vdash(\neg A\to B)\to(\neg B\to A)$
- Th. 15: $\vdash(A\to\neg B)\to(B\to\neg A)$

### 定理 16：反证法（3）

另一种更加直观的反证法。

$$
\vdash_{PC}(\neg A\to B)\to((\neg A\to \neg B)\to A)
$$

- 证明
    1. $(\neg A\to\neg B)\to(B\to A)$   $A_3$
    2. $B\to((\neg A\to \neg B)\to A)$   Th. 2
    3. $((\neg A\to \neg B)\to A)\to(\neg A\to\neg(\neg A\to\neg B))$   Th. 13
    4. $B\to(\neg A\to\neg(\neg A\to\neg B))$   2, 3 Th. 8
    5. $\neg A\to(B\to\neg(\neg A\to\neg B))$   Th. 2
    6. $(\neg A\to(B\to\neg(\neg A\to\neg B)))\to((\neg A\to B)\to(\neg A\to \neg(\neg A\to\neg B)))$   $A_2$
    7. $(\neg A\to B)\to(\neg A\to \neg(\neg A\to\neg B))$   5, 6 $r_{mp}$
    8. $(\neg A\to\neg(\neg A\to\neg B))\to((\neg A\to\neg B)\to A)$   $A_3$
    9. $(\neg A\to B)\to((\neg A\to\neg B)\to A)$   7, 8 Th. 8

### 定理 17：反证法（4）

同 Th. 16。

$$
\vdash_{PC}(A\to B)\to((A\to\neg B)\to\neg A)
$$

- 证明
    1. $(A\to\neg B)\to(A\to\neg B)$   Th. 1
    2. $A\to((A\to\neg B)\to\neg B)$   Th. 2
    3. $((A\to\neg B)\to\neg B)\to(B\to\neg(A\to\neg B))$   Th. 15
    4. $A\to(B\to\neg(A\to\neg B))$   2, 3 Th. 8
    5. $(A\to(B\to\neg(A\to\neg B)))\to((A\to B)\to(A\to\neg(A\to\neg B)))$   $A_2$
    6. $(A\to B)\to(A\to\neg(A\to\neg B))$   4, 5 $r_{mp}$
    7. $(A\to\neg(A\to\neg B))\to((A\to\neg B)\to\neg A)$   Th. 15
    8. $(A\to B)\to((A\to\neg B)\to\neg A)$   6, 7 Th. 8
    

### 定理 18：拆前件

针对 $(A\to B)\to C$ 的「万能公式」。

> 警钟长鸣：2022 年春的期末考试中，PC 系统的所有证明题都能用 Th. 18 轻松秒杀。
> 

$$
\vdash\neg A\to C, \vdash B\to C\iff\vdash (A\to B)\to C
$$

- 证明
    - 必要性（$\Rightarrow$）
        1. $\neg A\to C$   前提
        2. $(\neg A\to C)\to(\neg C\to A)$   Th. 14
        3. $\neg C\to A$   1, 2 $r_{mp}$
        4. $(\neg C\to A)\to((A\to B)\to (\neg C\to B))$   Th. 5
        5. $(A\to B)\to (\neg C\to B)$   3, 4 $r_{mp}$
        6. $B\to C$   前提
        7. $(B\to C)\to((\neg C\to B)\to(\neg C\to C))$   Th. 4
        8. $(\neg C\to B)\to (\neg C\to C)$   6, 7 $r_{mp}$
        9. $(A\to B)\to(\neg C\to C)$   5, 8 Th. 8
        10. $(\neg C\to C)\to C$   Th. 9
        11. $(A\to B)\to C$   9, 10 Th. 8
    - 充分性（$\Leftarrow$）
        1. $(A\to B)\to C$   前提
        2. $B\to(A\to B)$   $A_1$
        3. $B\to C$   2, 1 Th. 8
        4. $\neg A\to(A\to B)$   Th. 6
        5. $\neg A\to C$   4, 1 Th. 8
    

### 演绎定理

可以将「$\vdash$」进行前后「推动」，从而简化命题的证明。

$$
\Gamma\cup\{A\}\vdash B\iff\Gamma\vdash A\to B
$$

## 性质定理

### 合理性

PC 中的定理都是永真的。如果 $\Gamma\vdash A$，那么 $\Gamma\Rightarrow A$。

### 完备性

PC 中的任一永真式都是 PC 的定理，即如果 $\Gamma\Rightarrow A$，则 $\Gamma\vdash A$。

### 一致性

PC 中不存在公式 $A$ 使得 $\vdash A$ 和 $\vdash\neg A$ 同时成立。

### 不完全性

PC 中存在公式 $A$ 使得 $\vdash A$ 和 $\vdash\neg A$ 都不成立。

## 做题技巧

### 倒推

基本思路一般是从要证明的结论反向倒推，倒推到明显成立的定理 / 公理后，再正向誊抄就是证明过程了。

### 观察前后件特征

比如看见 $(\triangle\to\diamond)\to\Box$ 就可以尝试 Th. 18，见到有相同结构就可以尝试 Th.4 / Th. 5 以及 $A_2$。

### 善用前件互换

这很有用，不是吗？

### 演绎定理和「Th. 16 反证法」

对于 $\to$ 总是在后边的式子，可以多用演绎定理，没准有戏。

反证法是终级方法。任老师曰：「绝大多数题都能做出来，做不出来就是题出错了。」