##structure vs class in C++
the most important of  them is security. A Structure is not secure and cannot hide its
implementation details from the end user while a class is secure and can hide its programming
and designing details.

##const 限定符
`const int bufSize = 512 // 输入缓冲区大小`
因为const对象一旦创建后其值就不能再改变，所以const对象必须**初始化**。
初始值可以使任意复杂的表达式。
```objectivec
const int i = get_size();
const int j = 42;
const int k;
```

####初始化和const
在不改变 `const` 对象的操作中还有一种是初始化，如果利用一个对象区初始化另外一个对象，
则他们是不是`const`都无关紧要
```objectivec
int i = 42;
const int ci = i;
int j = ci; // 拷贝一个对象的值并不会改变它，一旦拷贝完成，新的对象就和原来的没什么关系了。
```

**默认状态下，const对象仅在文件内有效**。如果想在多个文件中使用，不管是声明还是定义都添加`extern`
```objectivec
//file.cc
extern const int bufSize = fcn();
//file.h
extern const int bufSize;
```

###const的引用
可以把引用绑定到const对象上。**对常量的引用reference to const**.
```objectivec
const int ci = 1024;
const int &r1 = ci; //正确，引用及其对象都是常量
int &r2 = ci; //错误，试图让一个非常量引用指向一个常量对象
```
由于c++语言并不允许随意改变引用所绑定的对象，所以从这层意义上理解所有的引用又都算是常量。
引用的对象是常量还是非常量可以决定其所能参与的操作、却无论如何都不会影响到引用和对象的绑定关系本身。

对const的引用可能引用一个并非const的对象
```objectivec
int i = 42; 
int &r1 = i; //引用ri绑定对象i
const int &r2 = i; //r2也绑定对象i，但是不允许通过r2修改i的值
r1 = 0; // r1并非常量，i的值修改为0
r2 = 0; // 错误：r2是一个常量引用
```

### 2,4,2 指针和const
和常量引用一样，指向常量的指针也没有规定其所指的对象必须是一个常量。
所谓指向常量的指针仅仅要求不能通过该指针改变对象的值，而没有规定哪个对象的值不能通过其他途径改变




