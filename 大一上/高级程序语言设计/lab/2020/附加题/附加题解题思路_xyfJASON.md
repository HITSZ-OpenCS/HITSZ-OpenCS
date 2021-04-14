附加题二和附加题三都比较简单，着重说一下附加题一。

附加题一单词纠错主要分两部分解决，一是计算编辑距离（$\textbf{Levenshtein}$ 距离），二是查找最小编辑距离并替换。

编辑距离用动态规划计算即可，具体步骤在下发的 pdf 里面写得很清楚了。

查找最小编辑距离是一个有意思的地方，如果直接暴力做是 $O(nm)$ 的，其中 $m$ 是待处理单词数，$n$ 是单词表大小。实测运行时间是 **56.26** 秒。

虽然解决了问题，但是我们当然不满足于此（划掉）。考虑到这是一个实际问题，**输错的单词并不会错的太离谱**，我们可以对单词表按单词长度排序，然后二分找到与待纠错单词的长度相等的单词区间，先在这个区间内查找，再逐步向两端扩展（即增加长度差），直到长度差大于当前已知的最小编辑距离就停止查找。这么做实测运行时间是 **7.01** 秒。

然而还有更快的做法。1973 年 $\textbf{W. A. Burkhard}$ 和 $\textbf{Robert M. Keller}$ 提出的 **BK 树**可以有效解决这个问题：[论文链接](https://www.researchgate.net/profile/Robert-Keller-12/publication/234803118_Some_Approaches_to_Best-Match_File_Searching/links/0fcfd5112a3d957de5000000/Some-Approaches-to-Best-Match-File-Searching.pdf)。这里还有一篇介绍 BK树的[博客](http://www.matrix67.com/blog/archives/333)。用 BK 树实测运行时间是 **0.47** 秒，完虐上面的两种做法。