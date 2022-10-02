# Java 基础

因为 Java 语言和 C/C++ 在很多语法上相似甚至完全一致（例如各种控制语句），因此这里只列出 Java 与 C 家族不同的语言特性。

## 数据类型

### 基本数据类型

Java 一共有 8 种「基本数据类型」。

| 类型 | 空间 | 范围 | 备注 |
| --- | --- | --- | --- |
| byte | 1 字节 | -128 — 127 |  |
| short | 2 字节 | -2^15 — 2^15 - 1 |  |
| int | 4 字节 | -2^31 — 2^31 - 1 |  |
| long | 8 字节 | -2^63 — 2^63 - 1 | 声明常量要加「L」 |
| float | 4 字节 | —— | 声明常量要加「F」 |
| double | 8 字节 | —— | 浮点数的默认类型 |
| char | 16 字节 | UTF-16 |  |
| boolean | —— | false 或 true | 不能用 0 和非 0 代替 |

### 引用类型

类 `class`、接口 `interface` 和数组都是引用类型。

## 输入输出

### 输入

Java 的标准输入流是一个 `InputStream` 对象，有两种常用的读取方式：

- 用读字符流的方法将 `System.in` 读到一个 `BufferedReader` 中。
    
    ```java
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    stdin.readLine() // <= 得到用户输入的字符串
    ```
    
- 用 `java.util.Scanner` 对 `System.in` 进行封装。
    
    ```java
    Scanner stdin = new Scanner(System.in);
    stdin.nextLine() // <= 得到用户输入的字符串
    ```
    

### 输出

- `System.out.print()` 不换行输出。
- `System.out.println()` 换行输出。
- `System.out.printf()` 格式化输出，语法同 C 标准库的 `printf()`。

## 数组

Java 中的「数组」是确定长度的，一经创建就不能再加长了。

### 声明和创建

在创建数组时，要么指定长度，要么给出所有的项。

```java
int[] arr = new int[3]; // 指定长度
double[] anotherArray = new double[]{ 2.1, 4.5, 4.2 }; // 指定项
```

### 长度和索引

可以使用 `arr.length` 得到一个数组的长度。数组的下标从 0 开始，到 `length - 1` 结束。

### 数组是引用类型

所谓「引用类型」，可以理解为 C 家族中的「指针」。下面的代码解释了「引用」的本质。

```java
int[] arr = new int[]{ 1, 4, 2, 5 };
System.out.println(arr[2]);       // 打印 2
arr = new int[]{ 7, 3, 6, 9 };    // 现在 arr 指向了一个新的数组，旧的数组会被 JVM 回收
System.out.println(arr[2]);       // 打印 6
```

### 数组中的引用类型

思考下面代码的输出：

```java
String[] name = { "HIT", "SZ", "C++" };
String s = name[2];
name[2] = "Java";
System.out.println(name[2]);
System.out.println(s);
```

结果为

```
Java
C++
```

内存映射图：

![Untitled](Java%20%E5%9F%BA%E7%A1%80%203a7a1a506d2a49c1bc5676caeba39fbe/Untitled.png)

### 「多维」数组

没有所谓的「多维数组」，它本质上是「数组的数组」。例如

```java
int[][] arr = new int[5][];
```

是一个长度为 5 的「数组」数组，它内部的 5 个数组因为现在还没有初始化，所以长度可以不给出。我们当然也可以在定义给出所有的项，如下：

```java
int[][] arr = new int[][]{ { 1, 4, 2}, {2, 1}, {9, 1, 5, 6} };
```

显然，多维数组中的每一行不一定要一样长。

## 异常

Java 的异常捕获结构为 `try` - `catch` - `finally`。其中 `catch` 和 `finally` 可以只出现一个。

```java
try {
		// 做点啥
} catch (/** 异常 **/) {
    // 出现异常时做的事
} finally {
    // 不管出现异常与否都要做的事
}
```

## 类与对象

### 对象

1. 定义：客观存在的具体实体，具有明确定义的状态和行为
2. 特征：标识符、属性、操作
    1. 属性：与对象关联的变量，描述对象的静态特性
    2. 操作：与对相关联的函数，描述对象的动态特性

### 类

1. 与对象
    1. 类是对象的抽象，是创建对象的模板
    2. 对象是类的具体事例
    3. 同一个类可以定义多个对象
2. 二者比较
    1. 类是静态的，在程序设计的时候就定义好了
    2. 对象是动态的，在程序执行的时候可以被创建、修改、删除

### 类的构造

类的访问权限：

![Untitled](Java%20%E5%9F%BA%E7%A1%80%203a7a1a506d2a49c1bc5676caeba39fbe/Untitled%201.png)

```java
// 见上表
public class Person {
		private String name;    // private: 只有本类能访问。
		protected int age;      // protected: 包外不能访问。但如果子类在包外，也能访问。
		int id;                 // friendly: 包外不能访问。如果子类在包外，也不能访问。
 		public boolean gender;  // public: 谁都可以访问
	
		public Person(String name, int age) {
				this.name = name;
				this.age = age;
				id = 1;
		}

		public Person(String name) {
				this(name, 22);
		}
}
```

### 静态类

1. 静态成员属于类所有而不是某一具体对象所有
2. 加载时间
    1. 静态成员在类加载的时候被静态地分配地址空间和方法的入口地址
    2. 静态属性当且仅当在类初次加载的时候初始化
3. 实例
    1. 非静态对象在创建对象的时候初始化，存在多个实例副本，各个对象之间的副本不互相影响
    2. 静态对象被所有的对象共享，在内存中只有一个副本
4. `static` 属性是全局属性，可以直接通过类名访问，所以又叫类属性
5. 调用限制
    1. `static` 方法不可访问非 `static` 的方法：非 `static` 的对象必须要实例化才能访问调
    2. 非 `static` 的方法可以访问 `static` 的方法：通过类名访问
6. 静态块
    1. 可以放在类的任何地方，类中可以有多个 `static` 块
    2. 语法：
        
        ```java
        class Person {
        		static {
        			totalNum = 10000;
        			System.out.println("static block run!");
        		}
        }
        ```
        
    3. 生命周期：在类加载的时候执行且只执行一次
    4. 用法：用于初始化静态变量和调用静态方法
7. 静态是否破坏了面向对象的特性？
    1. 静态属于类而非具体对象
    2. 具有一定程度上的全局性：初始化时加载到内存，并且所有对象有访问权限
    3. 保持类的封装性