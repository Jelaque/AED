#ifndef linkedList
#define linkedList
#include <iostream>
using namespace std;
template<class T>
class Node{
	public:
	  Node() {}
		T value;
		Node<T>* next;
		Node(const T&);
};
template<class T>
class LinkedList{
	typedef Node<T>* pNode;
	private:
		pNode pHead;
		pNode pLast;
	public:
		LinkedList();
		void pushFront(const T&);
		void pushBack(const T&);
		void popFront();
		void popBack();
		bool find(T);
		bool recursiveFind(T&, pNode&);
		T greaterElement();
		void deleteElement(T);
		LinkedList<T> concatenate(const LinkedList<T>&);
		LinkedList<T> intersection(const LinkedList<T>&);
		template<class U>
		friend ostream& operator<<(ostream& output, const LinkedList<U>& o){
  		pNode temp=o->pHead;
  		for (;temp;temp=temp->next)
    		output << temp->value << endl;
  		return output;
		}
		void insertedSort(T);
//
};
template<class T>
class DoubleNode{
  typedef DoubleNode<T>* pDNode;
	public:
	  T value;
		pDNode next;
		pDNode back;
		DoubleNode(const T&);
};
template<class T>
class DoubleLinkedList{
	typedef DoubleNode<T>* pDNode;
	private:
		pDNode pHead;
		pDNode pLast;
	public:
		DoubleLinkedList();
		void pushFront(const T&);
    void pushBack(const T&);
    void popFront();
    void popBack();
    bool find(const T&);
    void show();
		friend ostream& operator<<(ostream& output, const DoubleLinkedList<T>& o){
  		pDNode temp=o->pHead;
  		for (;temp!=NULL;temp=temp->next){
    		output << temp->value << endl;
  		}
  		return output;
		}
//
};
#define linkedListFunction
#include "linkedList.cpp"
#endif
