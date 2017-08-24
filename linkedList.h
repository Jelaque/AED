#include <iostream>
using namespace std;
template<class T>
class Node{
	public:
		T value;
		Node<T>* next;
		Node(const T&);
};
template<class T>
class LinkedList: public Node<T>{
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
    		output << temp->value << std::endl;
  		return output;
		}
//
};
template<class T>
class DoubleNode: public Node<T>{
	public: 
		Node<T>* back;
		DoubleNode(const T&);
};
template<class T>
class DoubleLinkedList: public DoubleNode<T>{
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
    template<class U>
		friend ostream& operator<<(ostream& output, const LinkedList<U>& o){
  		pDNode temp=o->pHead;
  		for (;temp;temp=temp->next)
    		output << temp->value << std::endl;
  		return output;
		}
//
};
