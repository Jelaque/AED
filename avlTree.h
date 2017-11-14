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
  public:
    AVLTree(): root=0;
    bool findNode(T d, AVLNode<T>**&p);
    bool addNode(T d);
    bool deleteNode(T d);
    AVLNode<T>* getFather(T d);
    bool Balance(T d);
};
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
  Balance(d);
  return true;
}
template<class T>
AVLNode<T>* AVLNode<T>::getFather(T d){
  AVLNode<T>**p=&root;
  AVLNode<T>* dad=*p;
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
