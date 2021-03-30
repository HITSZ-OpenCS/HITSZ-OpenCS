# 1 绪论

## 1.1 数理逻辑的发展简史

## 1.2 形式化公理系统

## 1.3 数理逻辑与计算机科学

# 2 命题逻辑的基本概念

## 2.1 命题与联结词

### 2.1.1 命题符号化

### 2.1.2 命题联结词及真值表

Q：否定词？A：$\neg$。

Q：合取词？A：$\wedge$。

Q：析取词？A：$\vee$。

Q：蕴含词？A：$\to$。

Q：双条件词？A：$\leftrightarrow $。

### 2.1.3 命题公式及真值表

Q：什么是指派？A：对命题公式中的命题变元的真值赋值。

Q：什么是重言式？A：对任一真值指派，其真值均为真的公式。

Q：什么是矛盾式？A：对任一真值指派，其真值均为假的公式。

Q：什么是可满足式？A：存在一个指派，使其真值为真的公式。

### 2.1.4 逻辑蕴涵与逻辑等价

Q：$A\Rightarrow B$ 是指什么？A：公式A逻辑蕴含公式B。

Q：什么是A逻辑蕴含B？A：对公式A，B，所有弄真A的指派也必弄真公式B。

Q：$A\Leftrightarrow B$ 是指什么？A：公式A与公式B逻辑等价。

Q：什么是A，B逻辑等价？A：$A\Rightarrow B \wedge B\Rightarrow A$

## 2.2 范式

### 2.2.1 基本概念

Q：什么是文字？A：原子命题变元及其否定。

Q：什么是合取式？A：文字的合取。

Q：什么是析取式？A：文字的析取。

Q：什么是合取范式？A：形如$A_{1} \wedge A_{2} \wedge \cdots \wedge A_n (n\geq 1)$，其中 A 为析取式。

Q：什么是析取范式？A：形如$A_{1} \vee A_{2} \vee \cdots \vee A_n (n\geq 1)$，其中 A 为合取式。

### 2.2.2 范式的求解

### 2.2.3 主范式

Q：什么是合取项？A：合取范式里的析取式。

Q：什么是析取项？A：析取范式里的合取式。

Q：什么是主合取范式？A：设命题公式A有n个变元，则其主合取范式的每个合取项的形式为$A_{j}=Q_{1} \vee Q_{2} \vee \cdots \vee Q_{n}$，其中$Q_i = p_i$或$\neg p_i,i = 1,\dotsc,n$

Q：什么是主析取范式？A：设命题公式A有n个变元，则其主析取范式的每个析取项的形式为$A_{j}=Q_{1} \wedge Q_{2} \wedge \cdots \wedge Q_{n}$，其中$Q_i = p_i$或$\neg p_i,i = 1,\dotsc,n$

Q：永真式无？A：主合取范式。

Q：永假式无？A：主析取范式。

## 2.3 联结词的扩充与规约

Q：或非词？A：$\downarrow$。

Q：与非词？A：$\uparrow$。

Q：异或词？A：$\forall$。

## 2.4 对偶式

Q：什么是对偶式？A：在仅含有联结词$\neg,\vee,\wedge$的命题公式A中，将$\vee$和$\wedge$对换，$T$和$F$对换，得到的公式称为A的对偶式，记为$A^*$。

Q：什么是内否式？A：将命题公式A中的所有变元前加$\neg$，记为$A^-$.

# 3 命题演算形式系统

## 3.1 命题逻辑演算形式系统

### 3.1.1 命题演算形式系统的组成

Q：字符集包括？A：圆括号()、联结词完备集{$\neg,\to$}、原子变元符。

Q：公理1的形式？A：$A1:A\to(B\to A)$。

Q：公理2的形式？A：$A2:(A\to(B\to C))\to((A\to B)\to(A\to C))$。

Q：公理3的形式？A：$A3:(\neg A\to\neg B)\to(B\to A)$。

Q：分离规则形式？A：$(A,A\to B)r_{mp}:B$。

### 3.1.2 命题演算形式系统的基本定理

Q：定理1的形式？A： $\vdash_{P C} A \rightarrow A$。

Q：定理2（前件互换）的形式？A：如果$A \rightarrow(B \rightarrow C)$，那么$B \rightarrow(A \rightarrow C)$。

Q：定理3（换前件）的形式？A：$\vdash_{P C}(A \rightarrow(B \rightarrow C)) \rightarrow(B \rightarrow(A \rightarrow C))$。

Q：定理4（加前件）的形式？A：$\vdash_{P C}(B \rightarrow C) \rightarrow((A \rightarrow B) \rightarrow(A \rightarrow C))$。

Q：定理5（加后件）的形式？A：$\vdash_{P C}(A \rightarrow B) \rightarrow((B \rightarrow C) \rightarrow(A \rightarrow C))$。

Q：定理6和7的形式？A：$\vdash \neg A \rightarrow(A \rightarrow B)$、$\vdash  A \rightarrow(\neg A \rightarrow B)$。

Q：定理8（三段式）的形式？A：如果$\vdash (A \rightarrow B),\vdash (B \rightarrow C)$，那么$\vdash (A \rightarrow C)$。

Q：定理9和11的形式？A：$\vdash_{P C}(\neg A \rightarrow A) \rightarrow A$、$\vdash(A \rightarrow \neg A) \rightarrow \neg A$。

Q：定理10和12的形式？A：$\vdash \neg \neg A \rightarrow A$、$\vdash A \rightarrow \neg \neg A$。

Q：定理13、14、15的形式？A： $\vdash(A \rightarrow B) \rightarrow(\neg B \rightarrow \neg A)$、$\vdash(\neg A \rightarrow B) \rightarrow(\neg B \rightarrow A)$、$\vdash(A \rightarrow \neg B) \rightarrow(B \rightarrow \neg A)$。

Q：定理16和17的形式？A：$\vdash(\neg A \rightarrow B) \rightarrow((\neg A \rightarrow \neg B) \rightarrow A)$、$\vdash(A \rightarrow B) \rightarrow((A \rightarrow \neg B) \rightarrow \neg A)$。

Q：定理17.5的形式？A：如果$\vdash \neg A \rightarrow C,\vdash B \rightarrow C$那么$\vdash(A \rightarrow B) \rightarrow C$。

Q：演绎定理内容？A：对PC中任意公式集$\Gamma$和$A,B$，有$\Gamma\cup\{A\}\vdash B$当且仅当$\Gamma\vdash A\to B$。

### 3.1.3 PC的性质定理

Q：PC的合理性是什么意思？A：PC中的定理都是永真的，如果$\Gamma\vdash A$，则$\Gamma\Rightarrow A$。 

Q：PC的一致性是什么意思？A：PC中不存在公式A使得$\vdash A$及$\vdash\neg A$同时成立。

Q：PC不是完全的，是什么意思？A：PC中存在公式A使得$\vdash A$及$\vdash\neg A$均不成立。

Q：PC的理论是什么？A：集合$Th(PC)=\{A|\vdash_{PC}A\}$。

Q：PC基于前提$\Gamma$的扩充是什么？A：集合$Th(PC\cup\Gamma)=\{A|\Gamma\vdash_{PC}A\}$。

Q：PC是完备的是什么意思？A：PC中任一永真式必为PC的定理，如果$\Gamma\Rightarrow A$，则$\Gamma\vdash A$。

## 3.2 自然演绎推理系统

### 3.2.1 自然演绎推理系统的组成

Q：ND采用的公理为？A：$\Gamma;A\vdash A$。

Q：假设引入规则为？A：$\cfrac{\Gamma \vdash B}{\Gamma ; A \vdash B}$。

Q：假设消除规则为？A：$\cfrac{\Gamma ; A \vdash B ; \Gamma ; \neg A \vdash B}{\Gamma \vdash B}$。

Q：$\vee$引入规则为？A：$\cfrac{\Gamma \vdash A}{\Gamma \vdash A \vee B}, \cfrac{\Gamma \vdash A}{\Gamma \vdash B \vee A}$。

Q：$\vee$消除规则为？A：$\cfrac{\Gamma_{;} A \vdash C, \Gamma ; B \vdash C, \Gamma \vdash A \vee B}{\Gamma \vdash C}$。

Q：$\wedge$引入规则为？A：$\cfrac{\Gamma \vdash A, \Gamma \vdash B}{\Gamma \vdash A \wedge B}$。

Q：$\wedge$消除规则为？A：$\cfrac{\Gamma \vdash A \wedge B}{\Gamma \vdash A}, \cfrac{\Gamma \vdash A \wedge B}{\Gamma \vdash B}$。

Q：$\to$引入规则为？A：$\cfrac{\Gamma ; A \vdash B}{\Gamma \vdash A \rightarrow B}$。

Q：$\to$消除规则为？A：$\cfrac{\Gamma \vdash A, \Gamma \vdash A \rightarrow B}{\Gamma \vdash B}$。

Q：$\neg$引入规则为？A：$\cfrac{\Gamma ; A \vdash B, \Gamma ; A \vdash \neg B}{\Gamma \vdash \neg A}$。

Q：$\neg$消除规则为？A：$\cfrac{\Gamma \vdash A, \Gamma \vdash \neg A}{\Gamma \vdash B}$。

Q：$\neg\neg$引入规则为？A：$\cfrac{\Gamma \vdash A}{\Gamma \vdash \neg\neg A}$。

Q：$\neg\neg$消除规则为？A：$\cfrac{\Gamma \vdash \neg\neg A}{\Gamma \vdash A}$。

Q：$\leftrightarrow$引入规则为？A：$\cfrac{\Gamma \vdash A \rightarrow B, \Gamma \vdash B \rightarrow A}{\Gamma \vdash A \leftrightarrow B}$。

Q：$\leftrightarrow$消除规则为？A：$\cfrac{\Gamma \vdash A \leftrightarrow B}{\Gamma \vdash A \rightarrow B}, \cfrac{\Gamma \vdash A \leftrightarrow B}{\Gamma \vdash B \rightarrow A}$。

### 3.2.2 自然演绎推理系统的基本定理

Q：定理3.2.1的形式？A：$\vdash_{\mathrm{ND}} A \vee \rightarrow A$。

Q：定理3.2.2的形式？A：$\vdash \neg(A \vee B) \leftrightarrow \neg A \wedge \neg B$。

Q：定理3.2.3的形式？A： $\vdash \neg(A \wedge B) \leftrightarrow \neg A \vee \neg B$。

Q：定理3.2.4的形式？A：$\neg A \rightarrow B \vdash \dashv A \vee B$。

Q：定理3.2.5的形式？A：$A \rightarrow B \vdash \dashv \neg A \vee B$。

Q：定理3.2.6的形式？A：$\vdash(A \wedge(B \vee C)) \leftrightarrow((A \wedge B) \vee(A \wedge C))$。

Q：定理3.2.7的形式？A：PC的公理均为ND的定理。

# 4 一阶谓词逻辑演算基本概念

## 4.1 引言

Q：谓词逻辑研究的对象是什么？A：原子命题的内部结构。

## 4.2 一阶谓词演算基本概念

Q：什么是个体词？A：用于表示研究对象的词。

Q：个体词可分为什么？A：个体常元与个体变元。

Q：通常用什么分别表示个体变元和个体常元？A：字母表靠后的小写字母表示个体变元，靠前的表示个体常元。

Q：什么是谓词？A：表示研究对象的性质或研究对象之间关系的词。

Q：通常用什么表示谓词？A：大写字母。

Q：什么是 n 元谓词？A：含有 n 个个体变元的谓词称为 n 元谓词。

Q：什么是个体域（论域）？A：个体变元的取值范围。

Q：个体元通常用什么表示？A：D。

Q：什么是函词？A：用于描述从一个个体域到另一个个体域的映射。

Q：什么是量词？A：用于限制个体词的数量。

Q：量词可分为什么？A：全称量词$\forall$和存在量词$\exists$。

Q：什么是项？A：个体变元、个体常元、n 元函词及以上三者的有限次复合。

Q：什么是合式公式？A：1.不含联结词的单个谓词，即原子谓词公式；<br>2.若A为合式公式，则$\neg$A也是合式公式；<br>3.若A，B为合式公式，且无变元x在A，B中一个是约束的，而在另一个是自由的，则A$\vee$B，A$\wedge$B，A$\to$B，A$\leftrightarrow$B均是合式公式；<br>4.若A为合式公式，而x在A中为自由变元，则$\exists xP(x),\forall xP(x)$均是合式公式；<br>5.以上有限次符合所形成的公式均为合式公式。

Q：什么是约束变元？A：受量词约束的个体变元称为约束变元。

Q：什么是自由变元？A：不受量词约束的个体变元。

Q：什么辖域？A：量词所约束的范围。

Q：什么是易名规则？A：将量词辖域中出现的某个约束变元改成另一个在该辖域中未出现的个体变元，公式中的其余部分保持不变。改名后的公式称为原公式的改名式。

Q：什么是可代入？A：设v为谓词公式A中的自由变元，且项t中不含A中的约束变元符（若有可易名），则称项t对v是可代入的。

Q：什么是代入？A：对公式A中的自由变元的所有自由出现都换为项t（必须是可代入的）$A_t^v$，记为。若A中无v则$A_t^v=A$。

Q：什么是全称化？A：设$v_1,v_2,\dotsc,v_n$为公式A中的自由变元，则$\forall v_{i_{1}} \forall v_{i_{2}} \cdots \forall v_{i_{r}} A$称为A的全称化，其中$1 \leqslant i_{1}, i_{2}, \cdots, i_{r} \leqslant n, 1 \leqslant r \leqslant N$。

Q：什么是全称封闭式？A：公式$\forall v_{i_{1}} \forall v_{i_{2}} \cdots \forall v_{i_{r}} A$称为A的全称封闭式。

## 4.3 自然语句的形式化

Q：谓词的自然语句特点是什么？A：X是xxx。

Q：函词的自然语句特点是什么？A：X的xxx。

# 5 一阶谓词演算形式系统

## 5.1 一阶谓词演算形式系统组成

### 5.1.1 一阶语言

Q：FC的字符集包括什么？A：个体变元、个体常元、n元函词、n元谓词、真值联结词、量词、技术性括号。

Q：FC的真值联结词包括什么？A：$\neg,\to$。

Q：FC的量词包括什么？A：$\forall$。

Q：$\exists xP(x)$的全称形式为？A：$\neg\forall x\neg P(x)$。

### 5.1.2 一阶逻辑系统的理论

Q：FC公理AX2的形式是？A：$\forall v A \rightarrow A_{i}^{v}$（项t对v可代入）。

Q：FC公理AX3的形式是？A：$\forall v(A \rightarrow B) \rightarrow(\forall v A \rightarrow \forall v B)$。

Q：FC公理AX4的形式是？A：$A \rightarrow \forall v A$（v在A中无自由出现）。

## 5.2 FC的基本定理

Q：定理5.2.1？A：$\vdash_{\mathrm{FC}} \forall v A \rightarrow A$。

Q：定理5.2.2？A：$\vdash A \rightarrow \neg \forall v \neg A \text { 或 } \vdash A \rightarrow \exists v A$。

Q：定理5.2.3？A：$\vdash \forall v A \rightarrow \exists v A$。

Q：定理5.2.4（全称推广）？A：若$\vdash A$则$\vdash\forall vA$。

Q：定理5.2.5？A：v 不在$\Gamma$的任一公式里自由出现，若$\Gamma\vdash A$则$\Gamma\vdash\forall vA$。

Q：定理5.2.6（演绎定理）？A：$\Gamma;A\vdash B$当且仅当$\Gamma\vdash A\to B$。

Q：定理5.2.7？A：$\Gamma;A\vdash\neg B$当且仅当$\Gamma;B\vdash\neg A$。

Q：定理5.2.8（反证法）？A：若FC的公式集$\Gamma\cup\{A\}$不一致，则$\Gamma\vdash\neg A$。

Q：定理5.2.9？A：设$\Gamma$为FC的公式集，A,B为FC的公式，且变元不在$\Gamma$的任一公式里自由出现，则<br>$\Gamma ; A \vdash B \text { 蕴含 } \Gamma ; \forall v A \vdash B \quad \text { 及 } \quad \Gamma ; \forall v A \vdash \forall v B$。

Q：定理5.2.10（存在消除）？A：设$\Gamma$为FC的公式集，A,B为FC的公式，且变元v不在$\Gamma$的任一公式里及公式B里自由出现，则由$\Gamma\vdash\exists vA$及$\Gamma;A\vdash B$可推出$\Gamma\vdash B$。

Q：定理5.2.11（替换原理）？A：设A,B为FC的公式，且满足$A\vdash\dashv B$。A是C的子公式，D是将公式C中若干个（未必全部）A的出现换为公式B所得的公式，则$C\vdash\dashv D$。

Q：定理5.2.12（改名定理）？A：在FC中，若A'是A的改名式，且A'改用的变元不在A中出现，则$A\vdash\dashv A'$。

## 5.3 一阶谓词形式系统

Q：一个闭公式如何成为一个命题？A：加上解释。     

Q：一个含有自由变元的公式经解释后得到什么？A：命题函数。

Q：对一阶语言中的项和公式的解释称作什么？A：结构。

Q：结构包括什么？A：论域D、对项和公式的解释$I$。

Q：通常用什么来表示结构？A：$U=<D,I>$。

Q：什么是解释？A：一个映射，将常元指定为论域D中的个体，将函词指定为D上的函数，将谓词指定为D上的关系。

Q：将全体结构的集合记为什么？A：T，因为这种结构集合常称为Tarski语义结构类。

Q：解释I下的指派$\bar{s}(t)=$？A：$\left\{\begin{array}{ll}s(v) & \text { 当 } t \text { 为变元 } v \text { 时 } \\ \bar{a} & \text { 当 } t \text { 为常元 } a \text { 时 } \\ \bar{f}^{(n)}\left(\bar{s}\left(t_{1}\right), \cdots, \bar{s}\left(t_{n}\right)\right) & \text { 当 } t \text { 为 } n \text { 元函词 } f^{(n)}\left(t_{1}, \cdots, t_{n}\right) \text { 时 }\end{array}\right.$。

Q：对于公式A在结构U=<D,I>及指派s下取值为真为假分别记为？A：$\vDash_{U} \mathrm{A}[s]$和$\nvDash_{U} \mathrm{A}[s]$。

Q：$\vDash_{U}A$表示什么？A：在结构U中，对于一切可能的指派s，公式A均为真。

Q：$\vDash A$或$\vDash_{T}A$表示什么？A：公式A在任何结构、任何指派中均为真。

Q：当 A 为原子公式$P^{(n)}\left(t_{1}, \cdots, t_{n}\right)$时，$\vDash_{U}A[s]$当且仅当？A：$<\bar{s}\left(t_{1}\right), \cdots, \bar{s}\left(t_{n}\right)>\in \bar{P}^{(n)}$，即n元谓词所描述的n元关系成立。

Q：当 A 为公式$\neg B$时，$\vDash_{U}A[s]$当且仅当？A：$\nvDash_{U} \mathrm{B}[s]$。

Q：当 A 为公式$\forall B$时，$\vDash_{U}A[s]$当且仅当？A：对每一个 $d\in D$有$\nvDash_{U} \mathrm{B}[s]$，其中指派$s(v \mid d)$表示对变元v用指定元素d赋值外，对其它变元的指派与s相同。

Q：$\vDash_{U} \exists v B[s]$当且仅当？A：存在$d\in D$有$\vDash_U B[s(v|d)]$

## 5.4 FC的性质定理

Q：FC的合理性是什么？A：对FC中的任一公式A，如果$\vdash_{FC}A$，则有$\vDash_T A$。

Q：FC的合理性，推广到公式集$\Gamma$是什么？A：若$\Gamma\vdash_{FC}A$，则有$\Gamma\vDash_T A$。

Q： 用什么表示演绎等价？A：$A\vdash\dashv B$。

Q：若$A\vdash\dashv B$，则有？A：A和B逻辑等价，即$A\vDash_T B$且$B\vDash_T A$。

Q：在FC中，若A'是A的改名式，且在什么条件下，A和A'逻辑等价？A：A'改用的变元不在A中出现。

Q：FC的完备性是什么？A：对FC中的任一公式B，如果$\vDash_T B$，则有$\vdash_{FC} B$。

Q：设FC的公式集$\Gamma$是一致的，且$\Gamma\nvdash A$，则？A：$\Gamma\cup\{\neg A\}$是一致的。