##function
- `std::unordered_set` is an associative container that contains a set
of unique objects of type key. Search, insertion, and removal
have average constant-time complexity.

    Internally, the elements are not sorted in any particular order,
but organized into buckets. Which bucket an element is placed into depends entirely on the hash of its value.
this allows fast access to individual elements, since once a hash is computed,
it refers to the exact bucket the element is placed into.

- `std::unordered_map` is an associative container that contains key-value pairs with
unique keys. Internally, the elements are not sorted in any particular order,
but organized into buckets. Which bucket an element is placed into depends entirely on the hash of its key.
this allowsfast access to individual elements.
```objectivec
#include <unordered_map>
#include <string>
#include <iostream>

int main(){
    // create an unordered_map of three strings
    std::unordered_map<std::string, std::string> u = {
            {"red", "#FF0000"}
            {"green", "#00ff00"}
    };
    for(const auto& n : u){
        std::cout<< "key:[" << n.first << "] Value:[" <<n.second << "]\n";  
}
    // add two new entries to the unordered_map
    u['black'] = "#0000"

}
```

- `std::shared_ptr` is a smart pointer that shared ownership of an
object through a pointer. Several `shared_ptr` objects may own the same object.
the object is destroyed and its memory deallocated when either of the following
happens:
    - the last remaining `shared_ptr` owning the object id destroyed;
    - the last remaining `shared_ptr` owning the object is assigned another pointer via...
```objectivec
struct Base
{
    Base() {std::cout <<" Base::Base()\n"; }
    ~Base() {std::cout << " Base::~Base()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
}



```

- `std::priority_queue` is a container adaptor that provides constant time lookup
of the **largest** element, at the expense of logarithmic insertion and extraction.
A user-provided Compare can be supplied to change the ordering. e.g. using `std::greater<T>`
would cause the smallest element to appear as the top(). 
working with a priority_queue is similar to managing a heap in some random access container, with
the benefit of not being able to accidentally invalidate the heap.

- `std::uses_allocator` provides a transparent specialization of the `std::uses_allocator`
type trait for `std::priority_queue`: the container adaptor uses allocator if and only of the
underlying container does.

- `std::map` is a storted associative container that contains key-value
pairs with unique keys.Keys are sorted by using the comparison function Compare.
Search, removal, and Insertion operations have logarithmic complexity. Maps are usually
implemented as _red-black trees_.
everywhere the standard library uses the compare requirements, uniqueness
is determined by suing the equivalence
relation. 

##《C++ Primer》第11章 关联容器
关联容器支持高效的关键字查找和访问。两个主要的associative-container类型是map和set.
map中的元素是一些关键字-值（key-value）。set中每个元素只包含一个关键字；set支持高效的关键字查询，
检查一个给定关键字是否在set中。例如，在某些文本处理过程中，可以用一个set来保存想要忽略的单词。



