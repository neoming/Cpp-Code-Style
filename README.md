# C++编程风格读书笔记
## Chapter1
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