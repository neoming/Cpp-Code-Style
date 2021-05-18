# C++编程风格读书笔记
## Chapter1 抽象
### 书中观点
+ 将共同的抽象提取出来并放到基类中
+ 一个类应该能够描述一组对象
+ 如果派生类之间的区别在于属性，则用数据成员来表示；如果在与行为，则用虚函数来表示
+ 如果通过公有继承来产生派生类，那么这个派生类应该是其基类的特化 
+ 多态并不是所有程序设计问题的解决方案
### 学习心得
+ 重构非常重要
+ 面向对象不是解决问题的唯一手段
+ 大多数情况下组合的方式比继承的方式更高效

## Chapter2 一致性
### 书中观点
+ 构造函数应该使得对象处于明确定义状态（初始化要做好）
+ 考虑使用默认参数的形式来代替函数重载的形式
+ 用一致的方式来定义对象的状态——这需要识别出类的不变性
+ 类的接口定义应该是一致的——避免产生困惑
+ 对于每一个new操作，都要有对应的delete操作
+ 避免对从不使用的状态信息进行计算和存储
+ 在定义operator=时， 我们要注意x=x的情况
+ 用一个通用的函数来代替重复的表达式序列

### 学习心得
+ 注意内存泄漏
+ operator=号考虑 x=x的情况
+ 做好一致性

## Chapter3 不必要的继承
### 书中观点
+ 找出简单的抽象
+ 识别出对实现的继承；可以使用私有基类或者（更好的方法是）使用成员对象
+ 考虑使用默认参数的形式来替代函数重载

### 学习心得
+ 大多数继承所采用的都是共有继承的形式：派生类同事继承了基类的借口和实现

## Chapter4 虚函数
### 书中观点
+ 派生类在处理继承而来的状态时必须与基类保持一致
+ 如果在共有基类中没有定义虚构函数，那么在所有的派生类或者派生类的数据成员中都应该没有定义析构函数
+ 通常情况下，基类的析构函数应该被声明为虚函数
+ 将共同的行为迁移到基类中
+ 降低耦合性——将类之间的交互最小化
+ 如果派生类之间的区别在于属性，则用数据成员来表示；如果在于行为，则用虚函数来表示
+ 没有哪个设计是完美的；过窄的设计要好于过宽的设计
+ 考虑使用默认参数的形式来代替函数重载的形式

### 学习心得
在典型的C++实现中，虚函数的调用通常要慢于常规函数的调用，这是因为在调用虚函数的时候，必须在对象的虚表中进行索引运算以找到所要调用的函数。这个额外的索引运算将会使得在每个虚函数的调用中额外增加两到三条指令以及两到三次内存引用。这些开销是否会对程序的整体性能产生显著影响，要取决于函数的调用频率，以及执行函数本身所需要的时间。

## Chapter5 运算符重载
### 书中观点
+ 编写清晰的程序——而不是为了展示自己聪明的程序
+ 重载运算符的含义必须是自然的，而不是为了展示程序员的聪明
+ 重载运算符必须能够与其他的运算符进行正确的交互
+ 确保重载运算符的行为是一致的
+ 在重载运算符时，应该保持一组相关运算符的完整性
+ 在定义运算符=时，要注意`x=x`这种特殊的情况
+ 在对运算符进行重载时，我们要避免使其他程序员产生困惑
+ 识别出对实现的继承；可以使用私有基类或者（更好的方法是）使用成员对象
+ 在对运算符进行重载时，我们要避免产生困惑
### 学习心得
如果在代码中存在着大量输入输出运算，那么重载运算符是值得的。否则采用实现方法的形式。

## Chapter6 包装
### 书中观点
+ 需要指导从函数中返回的指针的有效生存期
+ 独立的对象应该有独立的行为
+ 不要对某些基本的信息进行完全的封装——要使得这些信息可以通过某些方法来访问
+ 发生错误时，对象的行为应该是明确定义的
+ 要使得C++包装类能够改善C接口
### 学习心得
关键字`extern "C"`是链接说明符，表示这些函数是由C编译器来编译的
异常处理十分重要

## Chapter7 效率
### 书中观点
+ 降低耦合性——将类之间的交互最小化
+ 不能只通过主观臆测就作出判断，而是应该通过执行性能分析的结果来找出问题
+ 要对类的实现进行分析以找出性能问题的根源
+ 可以通过分析客户代码来找出性能问题的根源
+ 完整的接口有助于实现高效的客户代码
+ 找出简单的抽象
### 学习心得
三种提高C++效率的方法：
1. 通过修改被封装的实现来提高性能
2. 修改客户代码来更高效的使用现有接口
3. 如果接口本身就存在缺陷，就需要对类和客户都进行修改