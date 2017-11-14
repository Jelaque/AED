#include"stack.h"
#include"sbt.h"
template<class T>
void pre_orden(BNode<T>* ptr){
  Stack<BNode<T>*> container;
  while(ptr){
    std::cout<<ptr->data<<std::endl;
    if (ptr->der)
      container.push(ptr->der);
    if (ptr->izq)
      ptr=ptr->izq;
    else{
      if(container.isEmpty())
        ptr=NULL;
      else
        ptr=container.pop();
    }
  }
}

main(){
  SBT<int> tree;
  tree.addNode(10);
  tree.addNode(5);
  tree.addNode(15);
  tree.addNode(2);
  tree.addNode(7);
  tree.addNode(12);
  tree.addNode(17);
  pre_orden(tree.getHead());
  return 0;
}
