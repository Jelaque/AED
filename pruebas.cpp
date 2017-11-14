//#include <gtkmm.h>
#include <iostream>
struct Record{
  public:
    int ill;
    int dir;
  public:
    Record(): dir(0) {}
    Record(int _ill): ill(_ill), dir(0) {}
    Record(int _ill, int d): dir(d), ill(_ill){}
    bool operator==(Record& c2){
      if (this->ill==c2.ill)
        return true;
      else
        return false;
    }
    bool operator>(Record& c2){
      if (this->ill>c2.ill)
        return true;
      else
        return false;
    }
    int getIll() {return ill;}
    int getDir() {return dir;}
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
    std::cout<<ptr->value.getIll()<<std::endl;
    ptr=ptr->next;
  }
}
class foo{
  private:
    LinkedList<Record>* container;
  public:
    foo(){
      container = new LinkedList<Record>;
    }
    void made(){
      for(int i=0;i<5;++i){
        container->addNode(Record(i,i));
      }
    }
    void print(){
      Node<Record>* temp=container->getHead();
      for(int i=0;i<5;++i){
        std::cout<<temp->value.ill<<std::endl;
        temp=temp->next;
      }
    }
};

main(){
  char* a="tjfksada";
  char* b="tjfksadab";
  char*ptr=a;
  while(*ptr!=NULL){
    std::cout<<*ptr;
    ++ptr;
  }
  return 0;
}
/*std::ofstream ifile;
  ifile.open("ills.txt");
  if (ifile.is_open()){
    ifile << "Sindrome de  Capgras# En el Tratado de Psiquiatría de Hales-Talbott (Ancora, 1996) se define como: el paciente cree que una persona estrechamente relacionada con él ha sido sustituida por un doble. Y en la Sinopsis de Psiquiatría de H. Kaplan (Panamericana, 1999) como: la idea delirante de que otras personas, normalmente muy cercanas al paciente, han sido reemplazadas por dobles exactos, que son impostores.";
    ifile << "Esta enfermedad está relacionada con la pérdida del reconocimiento emocional de los rostros familiares. Su causa podría ser una desconexión entre el sistema de reconocimiento visual y la memoria afectiva.";
    ifile << "Es una de las falsas identificaciones que se han descrito en el 23-50% de los pacientes con demencia, así como el Síndrome de Frégoli, la confusión entre televisión y realidad o el Síndrome del huésped fantasma.@";
  }
  else
    std::cout << "error" << std::endl;
  ifile.close();
  std::string line;
  std::ifstream ofile;
  ofile.open("ills.txt");
  while (getline(ofile, line)){
    std::cout << line << std::endl;
  }
  ofile.close();
  ofile.open("ills.txt");
  int pos=0;
  char letter=' ';
  std::string ill;
  while (letter!='#'){
    ill+=letter;
    ofile.seekg(pos, std::ios::beg);
    ofile.get(letter);
    ++pos;
  }
  std::cout << ill << std::endl;
  ofile.close();*/
