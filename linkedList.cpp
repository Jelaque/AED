#include "linkedList.h"
///////clase Node//////////
template<class T>
Node<T>::Node(const T& _value): value(_value), next(NULL) {}
//////clase LinkedList///////
template<class T>
LinkedList<T>::LinkedList(): pHead(NULL), pLast(NULL) {}
template<class T>
void LinkedList<T>::pushFront(const T& _value){
	pNode pNew = new Node<T>(_value);
	if (!pHead)
		pHead = pLast = pNew;
	else{
		pNew->next = pHead;
		pHead = pNew;
	}
}
template<class T>
void LinkedList<T>::pushBack(const T& _value){
	pNode pNew = new Node<T>(_value);
	if(!pLast)
		pLast = pHead = pNew;
	else{
		pLast->next = pNew;
		pLast = pNew;
	}
}
template<class T>
void LinkedList<T>::popFront(){
	if(pHead){
		if (pHead==pLast)
			pLast=NULL;
		pNode temp = pHead;
		pHead = pHead->next;
		delete temp;
	}
}
template<class T>
void LinkedList<T>::popBack(){
	if(pLast){
		if (pHead==pLast){
			delete pLast;
			pLast = pHead = NULL;
		}
		else{
			pNode temp=pHead;
			while(temp->next!=pLast)
				temp=temp->next;	
			delete pLast;
			pLast=temp;
		}
	}	
}
template<class T>
bool LinkedList<T>::find(T _value){
	pNode temp = pHead;
	while (temp!=NULL){
		if(temp->value==_value)
			return true;
		temp=temp->next;
	}
	return false;
}
template<class T>
bool LinkedList<T>::recursiveFind(T& element, pNode& fnode){
	if (!fnode) return 0;
	if (fnode->value==element) return 1;
	else return recursiveFind(element, fnode->next);
}
template<class T>
void LinkedList<T>::deleteElement(T _value){
	if(!pHead) return;
	if (pHead->value==_value){
		if (pHead==pLast)
			pLast=NULL;
		delete pHead;
		pHead=NULL;
	}
	else{
		pNode back = pHead;
		pNode cur = back->next;
		for (;cur;cur=cur->next){
			if (cur->value==_value){
				back->next=cur->next;
				if (cur==pLast)
					pLast=back;
				delete cur;
				break;
			}
			back=cur;
		}
	}
}
template<class T>
T LinkedList<T>::greaterElement(){
	if (!pHead) return -1;
	T greater=pHead->value;
	pNode temp=pHead;
	for(;temp;temp=temp->next){
		if (temp->value>greater)
			greater=temp->value;	
	}
	return greater;
}
template<class T>
LinkedList<T> LinkedList<T>::intersection(const LinkedList<T>& list){
	LinkedList<T> newList = new LinkedList<T>;
	pNode temp = pHead;
	for (;temp;temp=temp->next){
    if (list->find(temp->value))
      if (!newList->find(temp->value))
				newList->pushBack(temp->value);
  }
	return newList;
}
template<class T>
LinkedList<T> LinkedList<T>::concatenate(const LinkedList<T>& list){
	LinkedList<T> newList = new LinkedList<T>;
  pNode temp = pHead;
	for (;temp;temp=temp->next){
		if (!newList->find(temp->value))
			newList->pushBack(temp->value);
	}
	temp=list->pHead;
	for(;temp;temp=temp->next){
		if (!this->find(temp->value))
			if (!newList->find(temp->value))
				newList->pushBack(temp->value);
	}
  return newList;
}
////////clase DoubleNode///////
template<class T>
DoubleNode<T>::DoubleNode(const T& _value): Node<T>(_value), back(NULL){}
///////clase DoubleLinkedList///////
template<class T>
DoubleLinkedList<T>::DoubleLinkedList(): pHead(NULL), pLast(NULL) {}
template<class T>
void DoubleLinkedList<T>::pushFront(const T& _value){
  pDNode pNew = new DoubleNode<T>(_value);
  if (!pHead)
    pHead = pLast = pNew;
  else{
    pNew->next = pHead;
		pHead->back = pNew;
    pHead = pNew;
  }
}
template<class T>
void DoubleLinkedList<T>::pushBack(const T& _value){
  pDNode pNew = new DoubleNode<T>(_value);
  if(!pLast)
    pLast = pHead = pNew;
  else{
    pLast->next = pNew;
		pNew->back = pLast;
    pLast = pNew;
  }
}
template<class T>
void DoubleLinkedList<T>::popFront(){
  if(pHead){
		if (pHead==pLast)
			pLast=NULL;
    pDNode temp = pHead;
    pHead = pHead->next;
		pHead->back=NULL;
		delete temp;
  }
}
template<class T>
void DoubleLinkedList<T>::popBack(){
  if(pLast){
    if (pHead==pLast){
			delete pLast;
			pLast=pHead=NULL;
		}
		else{
			pDNode temp = pLast->back;
			delete pLast;
			pLast=temp;
		}
  }
}
template<class T>
bool DoubleLinkedList<T>::find(const T& _value){
  pDNode temp = pHead;
  while (temp!=NULL){
    if(temp->value==_value)
      return true;
    temp=temp->next;
  }
  return false;
}
main(){
	return 0;
}
