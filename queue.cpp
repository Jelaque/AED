#include"node.h"
#include<iostream>
template<class T>
class Queue{
  private:
    Node<T>* first;
    Node<T>* last;
  public:
    Queue(): first(0), last(0) {}
    void push(T);
    void pop();
    void remove();
    bool isEmpty();
};
template<class T>
bool Queue<T>::isEmpty(){
  return (first==0);
}
template<class T>
void Queue<T>::push(T val){
  Node<T>* newNode = new Node<T>(val);
  if(isEmpty())
    first=last=newNode;
  else{
    newNode->next=last;
    last=newNode;
  }
}
template<class T>
void Queue<T>::remove(){
  if(!isEmpty()){
    Node<T>* temp=last;
    if (last==first)
      first==0;
    last=last->next;
    delete temp;
  }
}
template<class T>
void Queue<T>::pop(){
  if(!isEmpty()){
    std::cout<<first->value<<std::endl;
  }
}
main(){
  return 0;
}
