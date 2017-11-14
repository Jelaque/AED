#include<iostream>
template<class T>
class BNode{
  public:
    T data;
    BNode<T>* child[2];
  public:
    BNode(){child[0]=0; child[1]=0;}
    BNode(T d):data(d) {child[0]=0; child[1]=0;}
};
template<class T>
class SBT{
  private:
    BNode<T>* root;
    int numberNodesRecursive(BNode<T>*);
    void printRecursive(BNode<T>*);
  public:
    SBT(): root(0) {}
    bool findNode(T d, BNode<T>**&p);
    bool addNode(T d);
    bool greatestNode();
    bool greatestNodeRecursive(BNode<T>*);
    bool deleteNode(T d);
    int numberNodes();
    BNode<T>* getFather(T d);
    BNode<T>* getBrother(T d);
    BNode<T>* getUncle(T d);
    BNode<T>* getHead();
    void print();
};
template<class T>
bool SBT<T>::deleteNode(T d){
  BNode<T>** q;
  BNode<T>* ptr;
  if (findNode(d, q)){
    if((*q)->child[0] && (*q)->child[1]){
      BNode<T>** p = &(*q)->child[1];
      while((*p)->child[0])
        p=&(*p)->child[0];
      std::swap((*q)->data,(*p)->data);
      ptr=*p;
      *p=ptr->child[1];
      delete *p;
    }
    else{
      ptr = *q;
      if ((*q)->child[0])
        *q=ptr->child[0];
      else
        *q=ptr->child[1];
      delete ptr;
    }
    return true;
  }
  else
    return false;
}
template<class T>
bool SBT<T>::findNode(T d, BNode<T>**&p){
  p=&root;
  while(*p){
    if((*p)->data==d) return true;
    if((*p)->data>d) p=&((*p)->child[0]);
    else p=&((*p)->child[1]);
  }
  return false;
}
template<class T>
bool SBT<T>::addNode(T d){
  BNode<T>**p;
  if(findNode(d,p)) return false;
  *p=new BNode<T>(d);
  return true;
}
template<class T>
bool SBT<T>::greatestNode(){
  if(root){
    BNode<T>* temp=root;
    while(temp->child[1]){
      temp=temp->child[1];
    }
    std::cout<<temp->data<<std::endl;
    return true;
  }
  return false;
}
template<class T>
bool SBT<T>::greatestNodeRecursive(BNode<T>* _root){
  if(!_root)
    return false;
  if(!_root->child[1]){
    std::cout<<_root->data<<std::endl;
    return true;
  }
  else
    return greatestNodeRecursive(_root->child[1]);
}
template<class T>
int SBT<T>::numberNodes(){
  BNode<T>* _root=root;
  return numberNodesRecursive(_root);
}
template<class T>
int SBT<T>::numberNodesRecursive(BNode<T>* node){
  if(!node)
    return 0;
  else
    return 1+numberNodesRecursive(node->child[0])+numberNodesRecursive(node->child[1]);
}
template<class T>
BNode<T>* SBT<T>::getFather(T d){
  BNode<T>**p=&root;
  BNode<T>* dad=*p;
  while(*p){
    if((*p)->data==d){
      return dad;
    }
    dad=*p;
    if((*p)->data>d)
      p=&((*p)->child[0]);
    else
      p=&((*p)->child[1]);
  }
  return NULL;
}
template<class T>
BNode<T>* SBT<T>::getBrother(T d){
  BNode<T>* node=getFather(d);
  if(node){
    if (node->data>d)
      node=node->child[1];
    else
      node=node->child[0];
  }
  return node;
}
template<class T>
BNode<T>* SBT<T>::getUncle(T d){
  BNode<T>* node=getFather(d);
  if (node){
    return getBrother(node->data);
  }
}
template<class T>
void SBT<T>::print(){
  BNode<T>* cur=this->root;
  printRecursive(cur);
}
template<class T>
void SBT<T>::printRecursive(BNode<T>*node){
  if(node){
    printRecursive(node->child[0]);
    std::cout<<node->data<<" ";
    printRecursive(node->child[1]);
  }
}
template<class T>
BNode<T>* SBT<T>::getHead(){
  return root;
}
