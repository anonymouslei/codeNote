##boost graph
[看一下这个网站](https://www.boost.org/doc/libs/1_60_0/libs/graph/doc/using_adjacency_list.html)

###a quick tour of hte boost graph library
[reference](https://www.boost.org/doc/libs/1_42_0/libs/graph/doc/quick_tour.html)
the domain of graph data structures and algorithms is in some respects
more complicated than that of containers. The abstract iterator interface used by STL is not
sufficiently rich to encompass the numerous ways that graph algorithms may
traverse a graph. Instead, we formulate an abstract interface that serves the
same purpose for graphs that iterators do for basic containers.

the graph abstraction consists of a set of vertices(or nodes), and a set of
edges (or arcs) that connect the vertices. 
[example](https://www.boost.org/doc/libs/1_42_0/libs/graph/example/quick_tour.cpp)
### constructing a graph.
`adjacency_list`: `adjacency_list` is a template class with six
template class with six template parameters. the first two template arguments(vecS, vesS)
determine the data structure used to represent the out-edges for each
vertex in the graph and the data structure used to represent the graph;s
vertex set(). the third argument, `bidirectionalS` , selects
a directed graph that provides access to both out and in-edges.
the other options for the third argument are directedS which
selects a directed graph with only out-edges, and `undirectedS` which selects an undirected graph.

Once we have the graph type selected, we can create the graph in
by declaring a graph object and filling in edges using the `add_edge()` function fo the xx.
#### add_edge(u,v,g)
Inserts the edge(u,v) into the graph, and returns an edge descriptot
pointing to the new edge.

Insted of calling the `add_edge()` function for each edge, we
could use the `edge_iterator_constructor` of the graph. this is typical
more **efficient** than using `add_edge()`. Pointers to the edge_array
can be viewed as iterators, so we can call the iterator
constructor by passing pointers to the beginning and end of the
array.
```objectivec
template <class EdgeIterator>
adjacency_list(EdgeIterator first, EdgeIterator last, vertices_size_type n, edges_size_type m=0, const GraphProperty& p = GraphProperty())
    
```
Create a graph object with n vertices and with the edges specified in the
edge list given by the range [firsr, last). the Edge
###accessing the vertex set
Now that we have created a graph, we can use the graph interface to access
the graph data in different ways. First we can access all of the vertices in
the graph using hte _vertices()_ function of the VertexListGraph interface.
this function returns a _std::pair_ of vertex iterators. Dereferencing a vertex iterator
gives a vertex object. the type of the vertex iterator is given by the graph_traits class.
Note that different graph classes can have different associated associated
vertex iterator.
the property_map class is used to obtain the property map type for a
specific property and function call _get(vertex_index,g)_ returns the
actual property map object.
```objective-c++
int main(int, char*[])
{
    typedef graph_traits<Graph>::vertex_descriptor Vertes;
    
    //get the property map for vertex indices
    typedef property_map<Graph, vertex_index_t>::type IndexMap;
    IndexMap index = get(vertex_index, g);
    
    std::cout << <"Vertices(g) = ";
    typedef graph_traits<Graph>::vertex_iterator vertex_iter;
    std::pair<vertex_iter, vertex_iter>vp;
    for (vp = vertices(g); vp.first != vp.second; ++vp.first){
        Vertex v = *vp.first;
        std::cout << index[v] << " ";    
    }
    std::cout << std::endl;

    return 0;   

}
```
### accessing the edge set

the set of edges for a graph can be accessed with the edges() function
of hte EdgeListGraph interface. Similar to the _vertices()_ function,
this returns a pair of iterators, but in this case the iterators are edge
iterators. Dereferencing an edge iterator gives an edge object. the 
_source()_ and _target()_ functions return the two vertices that return
two vertices that are connected by the edge.

### the adjacency structure
in the next few examples we will explore the adjacency structure of
the graph from the point of view of a particular vertex. We will look
at the vertices' in-edges, out-edges, and its adjacent vertices. We will
encapsulate this in an "exercise vertex" function, and apply it to
each vertex in the graph. To demonstrate the STL-interoperability of BGL.
we will use the STL _for_each()_ function to iterate through the vertices and apply the function.
```objective-c++
int main(int, char*[])
{
    std::for_each(vertices(g).first, vertices(g).second, exercise_vertex<Graph>(g));
    return 0;   
}
```
we use a functor for _exercise_vertex_ instead of just a function because
the graph object will be needed when we access information about each
vertex; using a functor gives us a place to keep a reference to the graph
object during the execution of the _std::for_each()_. Also we template
the functor on the graph type so that it is reusable with different graph classes.
Here is the start of the _exercise_vertex_ functor:
```objective-c++
template <class Graph> struct exercise_vertex {
    exercise_vertex(Graph& g_): g(g_) {}
    Graph& g;
};
```
#### Vertex Descriptors
the first thing we need to know in order to write the operator() method
of hte functor is the type for the vertex objects of the graph. the vertex type will be the parameter
to the operator() method. to be precise, we do not deal will
actual vertex objects,but rather with vertex descriptors.
the vertex descriptor is something provided by each graph type
that can be used to access information about the graph via the _out_edges()_,
_in_edges(), adjacent_vertices()_, and property map functions that are described in the following sections.
**the _vertex_descriptor_ type is obtained through the _graph_traits_ class.**
the typename keyword used below is necessary because the type on the
left hand side of hte scope::op




###Extending Algorithms with Visitors
often times an algorithm in a library almost does what you need, but
not quite. For example, in the previous section we used Dijkstra's
algorithm to caluculate hte shortes distance to each vertex, but perhaps
we also wanted to revord the tree of shortest paths. One way to do this
is to record the predecessor for each node in the shortest-pahts tree.

It would be nice if we just add that little bit extra needed to record the predecessors.
In the BGL this role is fulfilled by visitors.

A visitor is like a functor, but instead of having just on "apply" method,
it has several. Each of these methods get invoked at certain well-defined
points within the algorithm. the visitor methods are explained in detail
in Section Visitor Concepts. The BGL provides a number of visitors for
some common tasks including a predecessor recording visitor. the user is encouraged to
write his or her own visitors as a way of extending the BGL. Here we will
take a quick look at. the functionality of the _record_processors_ visitor is separated into two parts.
For the storage and access of the predecessor property, we will use a
property map. the predecessor visitor will then only be respinsible for what parent to record.
to implement this, we create a _record_predecessors_ class and template it on the
predecessor preperty map _PredecessorMap_. Since this visitor will only be filling in
one of the visitor methods, we will inherit from dijkstra_visitor which
will provide empty methods for the rest. The constructor of the predecessor_recorder will
take the property map object and save it wawy in a data member.

```objective-c++
template <class PredecessorMap>
class record_predecessors : public dijkstra_visitro<>{
public:
    record_predecessors(PredecessorMap p): m_predecessor(p) {}
    
    template <class Edge, class Graph>
    void edge_relaxed
};
```
we are now ready to use the _record_predecessors_ in Dijkstra's algorithms. 
```objective-c++
using std::vector;
using std::cout;
using std::endl;
vector<Vertex> p
```
the job of recording the predecessors is quite simple. When Dijkstra's
algorithm relaxes an edge we record the source vertex as the predecessor of
the target vertex. Later, if the edge is relaxed agin the predecessor property will be
overwritten by the new predecessor.

###a star search
[reference](https://www.boost.org/doc/libs/1_72_0/libs/graph/example/astar-cities.cpp)

### graph_traints<Graph>
just like the iterators of STL, graphs have associated types.
as stated in the various graph concepts, a graph has quite a few associated
types: _vertex_descriptor, edge_descriptor, out_edge_iterator, ect._
any particular graph concepts will not require that all
of hte following associated types be defined. when implementing
a graph class that fullfils one or more graph concepts,
for associated types that are not 


##optional
### introduction
class template **optional** is a wrapper for representing 'optional'
or 'nullable' objects who may not contain a valid value. Optional objects offer
full value semantics; they are good for passing by value and usage inside
STL containers. This is a header-only library.
###problem
suppose we want to read a parameter form a config file which represents some integral value,
let's call it "MaxValue". it is possible that this parameter is not specified; such 
situation is no error. It is valid to not specify the parameter
and in that case the program is supposed to behave
slightly differently. Also, suppose that any possible calue of type **int**
 is a valid value for "MaxValue", so we cannot just use -1 to represent the
 absence of the parameter in the config file.我们希望在没有参数的时候，函数也并不报错。
但是我们还是要区分出来没有参数这种情况。因为-1也是一种int的可能性，所以我们不能用
 -1来代表缺少参数这种情况。optional就是想解决上述问题的一个函数。
###solution
```objective-c++
#include <boost/optional.hpp>

boost::optional<int> getConfigParam(std::string name); // return either an int or a 'not-an-int'

int main()
{
    if(boost::optional<int> oi = getConfigParam("MaxValue"))    
        runWithMax(*ow);
    else
        runWithNoMax();
}
```
## tie
[reference](https://www.boost.org/doc/libs/1_58_0/libs/tuple/doc/tuple_users_guide.html)
a tuple is a fixed size collection of elements. In a programming language,
a tuple is a data object containing other objects as elements. these
element objects may be of different types.

Tuples are convenient in many circumstances. For instance, tuples make it easy
to define functions that return more than one value.

###Tiers
tiers are tuples, where all elements are of non-const reference types. 
```objective-c++
int i; char c; double d;
tie(i, c, a);
```
the above tie function creates a tuple of type `tuple<int&, char&, double&>`.
the same result could be achieved with the call `make_tuple(ref(i),ref(c),ref(a))`.


###问题：
- 寻找可以添加性质的edge
