* C++在c++11标准中引入了lambda表达式，一般用于定义匿名函数，使得代码更加灵活简洁。lambda表达式与普通函数类似，也有参数列表、返回值类型和函数体，只是它的定义方式更简洁，并且可以在函数内部定义。

** 什么是Lambda表达式
最常见的lambda的表达式写法如下
```
auto plus = [] (int v1, int v2) -> int { return v1 + v2; }
int sum = plus(1, 2);
```
