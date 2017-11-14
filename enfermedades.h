#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Record{
  public:
    char *ill;
    long dir;
  public:
    Record(): dir(0) {}
    Record(char* _ill): ill(_ill), dir(0) {}
    Record(char* _ill, long d){
      char* ptr1=ill;
      char* ptr2=_ill;
      while(*ptr2!=NULL){
        *ptr1=*ptr2;
        ++ptr1;
        ++ptr2;
      }
      dir=d;
    }
    bool operator==(Record& c2){
      return strcmp(this->ill,c2.ill);
    }
    bool operator>(Record& c2){
      char* ptr1=this->ill;
      char* ptr2=c2.ill;
      while(*ptr1!=NULL || *ptr2!=NULL){
        if (*ptr1>*ptr2) return true;
        else if (*ptr1==*ptr2){
          ++ptr1;
          ++ptr2;
        }
        else
          return false;
      }
    }
};
template<class T>
class Node{
  public:
    T value;
		Node<T>* next;
		Node(T val): value(val), next(0) {}
};
template<class T>
class LinkedList{
	typedef Node<T>* pNode;
	private:
		pNode pHead;
		pNode pLast;
	public:
		LinkedList();
	  bool addNode(T);
		bool deleteNode(T);
		bool findNode(T, Node<T> **&);
    void p();
    friend class Record;
    Node<T>* getHead() {return pHead;}
};
class Ills{
  private:
    LinkedList<Record>* listIlls;
  public:
    Ills();
    void index(char*);
    void print(char*,char*);
    void p();
};
