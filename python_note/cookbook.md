#cookbook
[python3-cookbook](https://python3-cookbook.readthedocs.io/zh_CN/latest/c04/p04_implement_iterator_protocol.html)

[toc]

### 4.2 代理迭代
#### 问题
你构建了一个自定义容器对象，里面包含有列表、元组或其他可迭代对象
####解决方案
`__iter__()`
```python
class Node:
    def __init__(self, value):
        self._value = value
        self._children = []

    def __repr__(self):
        return 'Node({!r})'.format(self._value)

    def add_child(self, node):
        self._children.append(node)

    def __iter__(self):
        return iter(self._children)

# Example
if __name__ == '__main__':
    root = Node(0)
    child1 = Node(1)
    child2 = Node(2)
    root.add_child(child1)
    root.add_child(child2)
    # Outputs Node(1),Node(2)
    for ch in root:
        print(ch)

            
```
### 4.3 使用生成器创建新的迭代模式
如果你想实现一种新的迭代模式，使用一个生成器函数来定义它。下面是一个生产某个范围内浮点数的生成器
```python
def frange(start, stop, increment):
    x = start
    while x < stop:
        yield x
        x += increment
```

为了使用这个函数，你可以用for循环迭代它或者使用其他接受一个可迭代对象的函数（比如`sum()`,
`list()`等）
```pydocstring
>>> for n in frange(0, 4, 0.5):
...     print(n)
...

>>> list(frange(0, 1, 0.125))
[0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875]
```
... 没写完


###4.4 实现迭代器协议
目前为止，在一个对象上实现迭代最简单的方式是使用一个生成器函数。
在4.2小节中，使用Node类来表示属性数据结构。你可能想实现一个以深度优先方式遍历树形节点的生成器。
下面是代码示例
