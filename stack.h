#include"node.h"
#include<iostream>
template<class T>
class Stack{
  private:
    Node<T>* top;
  public:
    Stack(): top(0) {}
    void push(T);
    T pop();
    void removeBack();
    bool isEmpty();
};
template<class T>
bool Stack<T>::isEmpty(){
  return (top==0);
}
template<class T>
void Stack<T>::push(T val){
  //std::cout<<"push: "<<val->data<<std::endl;
  Node<T>* newNode = new Node<T>(val);
  if(isEmpty())
    top=newNode;
  else{
    newNode->next=top;
    top=newNode;
  }
}
template<class T>
void Stack<T>::removeBack(){
  if(!isEmpty()){
    Node<T>* temp=top;
    top=top->next;
    delete temp;
  }
}
template<class T>
T Stack<T>::pop(){
  T val=top->value;
  this->removeBack();
  return val;
}
