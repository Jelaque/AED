template<class T>
class Node{
	public:
		T value;
		Node<T>* next;
	public:
		Node(const T);
};
template<class T>
Node<T>::Node(const T val): value(val), next(0){}
