#include"enfermedades.h"
using namespace std;
template<class T>
LinkedList<T>::LinkedList(): pHead(0) {}
template<class T>
bool LinkedList<T>::addNode(T data){
	Node<T> **p;
	if(!findNode(data, p)){
		Node<T> *newNode = new Node<T>(data);
		newNode->next=*p;
		*p=newNode;
		return true;
	}
	return false;
}
template<class T>
bool LinkedList<T>::deleteNode(T data){
	Node<T> **p;
	if (findNode(data, p)){
		Node<T>* temp = *p;
		*p=(*p)->next;
		delete temp;
		return true;
	}
	return false;
}
template<class T>
bool LinkedList<T>::findNode(T data, Node<T> **&p){
	p=&pHead;
	while(*p){
		if((*p)->value==data)
			return true;
		if((*p)->value>data)
			return false;
		p=&(*p)->next;
	}
	return false;
}
template<class T>
void LinkedList<T>::p(){
  Node<T>* ptr=pHead;
  while(ptr){
    cout<<ptr->value.getIll()<<endl;
    ptr=ptr->next;
  }
}
Ills::Ills(){
  listIlls = new LinkedList<Record>;
}
void Ills::index(char* filename){
	ifstream file(filename);
	char keyName[80];
	char information[5000];
	long address = 0;
	while(!file.eof()){
		file.getline(keyName,80,'#');
		file.getline(information,5000,'@');
		address+=(long)strlen(keyName)+1;
		listIlls->addNode(Record(keyName,address));
    address+=strlen(information)+2;
	}
	file.close();
}
void Ills::print(char* key,char* filename){
  /*Node<Record>**p;
  ifstream file(filename);
  if(listIlls->findNode(Record(key),p)){
    cout<<"ok"<<endl;
    char info[5000];
    long dir=(*p)->value.dir;
    file.seekg(0,ios::beg);
    file.seekg(dir);
    file.getline(info,5000,'$');
    cout<<(*p)->value.ill<<endl;
    cout<<info<<endl;
  }
  file.close();
  */
}
void Ills::p(){
  Node<Record>* ptr=listIlls->getHead();
  while(ptr){
    cout<<ptr->value.ill<<endl;
    ptr=ptr->next;
  }
}
main(){
  Ills ills;
  char a[]="Ebola";
  char b[]="enfermedades.txt";
  ills.index(b);
  ills.p();
	return 0;
}
