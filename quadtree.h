typedef int size;
template<class T>
class NodeQTree{
  public:
    T data;
    NodeQTree<T>* [4];
    NodeQTree(T _data){
      for(int i = 0; i < 4; ++i)
        NodeQTree<T>[i] = NULL;
    }
};
template<class T>
class Quadtree{
  private:
    NodeQTree<T>* root;
    size width;
    size height;
  public:
    Quadtree(){}
    Quadtree(char* image){}
    void recursiveDivide(char* image):
    /*void Insert(T d);
    void Delete(T d);*/
    void Insert(size X, size Y);
    void Delete(size X, size Y);
    }
};
