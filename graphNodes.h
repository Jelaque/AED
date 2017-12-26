#include<list>
#include<set>
#include"avlTree.h"
using namespace std;
template <class V, class E>
class Vertex;
//
template<class V, class E>
class Edge{
  public:
    E distance;
    mutable Vertex<V,E>* v_arrival;
    Edge(E d, Vertex<V, E>* dir): distance(d), v_arrival(dir) {}
    friend bool operator <(const Edge<V,E>& a, const Edge<V,E>& b){ return a.distance < b.distance; }
    friend bool operator >(const Edge<V,E>& a, const Edge<V,E>& b){ return a.distance > b.distance; }
    friend bool operator ==(const Edge<V,E>& a, const Edge<V,E>& b){ return a.distance == b.distance; }
    friend bool operator <=(const Edge<V,E>& a, const Edge<V,E>& b){ return a.distance <= b.distance; }
    friend bool operator >=(const Edge<V,E>& a, const Edge<V,E>& b){ return a.distance >= b.distance; }
    friend bool operator !=(const Edge<V,E>& a, const Edge<V,E>& b){ return a.distance != b.distance; }
};
template<class V, class E>
class Vertex{
  public:
    V data;
    mutable set< Edge<V,E> > axes;
    Vertex(V d): data(d) {}
    friend bool operator <(const Vertex<V,E>& a, const Vertex<V,E>& b){ return a.data < b.data; }
    friend bool operator >(const Vertex<V,E>& a, const Vertex<V,E>& b){ return a.data > b.data; }
    friend bool operator ==(const Vertex<V,E>& a, const Vertex<V,E>& b){ return a.data == b.data; }
    friend bool operator <=(const Vertex<V,E>& a, const Vertex<V,E>& b){ return a.data <= b.data; }
    friend bool operator >=(const Vertex<V,E>& a, const Vertex<V,E>& b){ return a.data >= b.data; }
    friend bool operator !=(const Vertex<V,E>& a, const Vertex<V,E>& b){ return a.data != b.data; }
};
template<class V, class E>
class CompleteEdge: public Edge<V,E>{
  public:
    Vertex<V, E>* v_going;
    CompleteEdge(E d, V dir_g, V dir_a): v_going(dir_g), Edge<V, E>(d, dir_a) {}

};
