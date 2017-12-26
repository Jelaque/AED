#include<iostream>
template<class T>
class AVLNode{
  public:
    T data;
    int balance;
    AVLNode<T>* child[2];
  public:
    AVLNode(){child[0]=0; child[1]=0;balance=0;}
    AVLNode(T d):data(d) {child[0]=0; child[1]=0; balance=0;}
};
template<class T>
class AVLTree{
  private:
    AVLNode<T>* root;
    AVLNode<T>* last;
    void printRecursive(AVLNode<T>*);
  public:
    AVLTree(): root(0) {}
    bool findNode(T d, AVLNode<T>**&p);
    bool addNode(T d);
    bool deleteNode(T d);
    AVLNode<T>* getFather(T d);
    bool balance(T d);
    AVLNode<T>* getHead();
    void print();
};
template<class T>
AVLNode<T>* AVLTree<T>::getHead() {return root;}
template<class T>
bool AVLTree<T>::findNode(T d, AVLNode<T>**&p){
  p=&root;
  while(*p){
    if((*p)->data==d) return true;
    if((*p)->data>d) p=&((*p)->child[0]);
    else p=&((*p)->child[1]);
  }
  return false;
}
template<class T>
bool AVLTree<T>::addNode(T d){
  AVLNode<T>**p;
  if(findNode(d,p)) return false;
  *p=new AVLNode<T>(d);
  last = *p;
  balance(d);
  return true;
}
template<class T>
AVLNode<T>* AVLTree<T>::getFather(T d){
  AVLNode<T>**p=&root;
  AVLNode<T>* dad=NULL;
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
bool AVLTree<T>::balance(T d){
  if (!getFather(d))
    return false;
  if(getFather(d)->data>d){
    --getFather(d)->balance;
    balance(getFather(d)->data);
  }
  else {
    ++getFather(d)->balance;
    balance(getFather(d)->data);
  }
}
template<class T>
void AVLTree<T>::print(){
  AVLNode<T>* cur=this->root;
  printRecursive(cur);
}
template<class T>
void AVLTree<T>::printRecursive(AVLNode<T>*node){
  if(node){
    printRecursive(node->child[0]);
    std::cout<<node->data<<" ";
    printRecursive(node->child[1]);
  }
}
